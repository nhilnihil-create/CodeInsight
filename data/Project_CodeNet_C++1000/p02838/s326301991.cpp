#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll mod(ll a, ll m)
{
    return ((a % m) + m) % m;
}

ll solve(int, const vector<ll>& xs)
{
    ll ans = 0;

    for (ll mask = 1, i = 0; i < 61; ++i, mask <<= 1)
    {
        ll zeros = 0, ones = 0;

        for (auto x : xs)
            (x & mask) ? ++ones : ++zeros;

        ll total = mod(ones * zeros, MOD);
        ll amount = mod(mod(mask, MOD) * total, MOD);

        ans = mod(ans + amount, MOD);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
