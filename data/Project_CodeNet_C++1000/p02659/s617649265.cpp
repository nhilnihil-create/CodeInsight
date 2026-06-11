#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <math.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;

int main()
{
    char decimal;
    ll A, B_int;
    ld B_frac;

    std::cin >> A >> B_int >> decimal >> B_frac;
    print(std::fixed << (ll)(A * (B_int*100 + B_frac) / 100));
    return 0;
}