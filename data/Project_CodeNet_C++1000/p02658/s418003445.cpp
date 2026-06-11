#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;

int main()
{
    int N;
    std::cin >> N;
    ll a, res = 1;
    bool flag = false;
    
    floop(N)
    {
        std::cin >> a;

        if(a == 0)
        {
            res = 0;
            break;
        }

        else if(flag)
            continue;

        else
        {
            if(INF/a < res)
            {
                res = -1;
                flag = true;
                continue;
            }
            res *= a;
        }
    }
        
    print(res);

    return 0;
}