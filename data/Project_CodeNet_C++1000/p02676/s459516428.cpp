#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <utility>

typedef long long ll;
typedef unsigned long long ull;

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;

int main()
{
    int K, len;
    std::string S, res="";

    std::cin >> K;
    std::cin >> S;

    len = S.length();

    if(len <= K)
    {
        print(S);
    }

    else
    {
        print(S.substr(0, K) + "...");
    }

    return 0;
}