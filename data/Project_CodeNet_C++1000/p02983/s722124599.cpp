// https://atcoder.jp/contests/abc133/tasks/abc133_c
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    constexpr ll mod= 2019;
    ll L, R;
    cin >> L >> R;
    ll d = R - L;
    if (d >= 2019)
    {
        printf("0\n");
        return 0;
    }

    ll ans = 2020;
    for (ll i = L; i < R; ++i)
    {
        for (ll j = L + 1; j <= R; ++j)
        {
            ll r = (i * j) % mod;
            if (r < 0) r = (r + mod) % mod;
            ans = min(ans, r);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
