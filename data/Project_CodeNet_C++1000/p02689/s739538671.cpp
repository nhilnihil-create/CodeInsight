#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> h[i];
    }

    std::vector<int> obs(n);
    // obs = 0(未比較), 1(少なくともどれか１つより低いか同じ), 2(他のどれよりも高い)
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (h[a - 1] < h[b - 1])
        {
            if (obs[b - 1] == 0)
            {
                obs[a - 1] = 1;
                obs[b - 1] = 2;
            }
            else
            {
                obs[a - 1] = 1;
            }
        }
        else if (h[b - 1] < h[a - 1])
        {
            if (obs[a - 1] == 0)
            {
                obs[a - 1] = 2;
                obs[b - 1] = 1;
            }
            else
            {
                obs[b - 1] = 1;
            }
        }
        else //h[a - 1] = h[b - 1]
        {
            obs[a - 1] = 1;
            obs[b - 1] = 1;
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (obs[i] == 0 || obs[i] == 2)
        {
            count++;
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}