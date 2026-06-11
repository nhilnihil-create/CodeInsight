#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <iterator>
#include <cmath>
#include <deque>
using namespace std;

pair<long long, long long> process(long long d, long long c)
{
    if (c == 1)
        return { d, 0 };
    if (c % 2) {
        auto p = process(d, c - 1);
        long long x = d + p.first;
        if (x >= 10)
            return { x / 10 + x % 10, 2 + p.second };
        else
            return { x, 1 + p.second };
    }
    else {
        auto p = process(d, c / 2);
        long long x = p.first + p.first;
        if (x >= 10)
            return { x / 10 + x % 10, 2 + 2 * p.second };
        else
            return { x, 1 + 2 * p.second };
    }
}

int main()
{
    {
        if (fopen("input.txt", "r")) {
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        }
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long m;
    cin >> m;
    long long ans = -1;
    long long x = 0;
    for (long long i = 0; i != m; ++i) {
        long long d, c;
        cin >> d >> c;
        auto ret = process(d, c);
        ans += ret.second;
        x += ret.first;
        ++ans;
        if (x >= 10) {
            ++ans;
            x = x / 10 + x % 10;
        }
    }
    cout << ans;
    return 0;
}