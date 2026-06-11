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
    int X, K=1;
    std::cin >> X;

    for(int i = 1; i <= 360; ++i)
    {
        if((X*i) >= 360)
        {
            if((X*i) % 360 == 0)
                break;

            if((X*i) % 180 == 0)
            {
                K *= 2;
                break;
            }
        }
        K++;
    }

    print(K);
    return 0;
}