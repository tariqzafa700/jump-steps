#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int jump(vector<int>& steps) {
    vector<int> max_till(steps.size(), 0);

    for(int i = 0;i < steps.size();++i)
    {
        if(max_till[i] == -1)
        {
            continue;
        }
        int limit = (i + steps[i]) > (steps.size() - 1) ? (steps.size() - 1) : (i + steps[i]);
        for(int j = limit;j >= i + 1 ;--j)
        {
            if(steps[j] + j - i <= steps[i] && j != steps.size() - 1)
            {              
                max_till[j] = -1;
                continue;
            }
            if(max_till[j] == 0)
            {
                max_till[j] = max_till[i] + 1;
            }
            else if(max_till[j] > 0 && max_till[i] + 1 < max_till[j])
            {
                max_till[j] = max_till[i] + 1;
            }

        }
    }
    return max_till[steps.size() - 1];
}

int main(int, char**) {
    vector<int> steps{1, 3, 4, 1, 1, 4, 1, 2, 2, 4};
    //vector<int> steps{2, 3, 1, 1, 4};
    //vector<int> steps{5, 4, 3, 2, 1, 1, 0};
    //vector<int> steps{2, 1};
    //vector<int> steps{1, 2, 3};
    //vector<int> steps{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    //vector<int> steps{9,7,9,4,8,1,6,1,5,6,2,1,7,9,0};
    cout << jump(steps);
}
