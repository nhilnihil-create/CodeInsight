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
    std::string N;
    std::cin >> N;
    int len = N.length();

    switch(N[len-1])
    {
        case '3':
            print("bon");
            break;
        case '2':
        case '4':
        case '5':
        case '7':
        case '9':
            print("hon");
            break;
        case '0':
        case '1':
        case '6':
        case '8':
            print("pon");
            break;
    }

    return 0;
}