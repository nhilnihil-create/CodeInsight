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

ll solve(int N, ll K, const vector<ll>& xs)
{
    vector<ll> ps(N + 1);
    ps[0] = 0;

    for (int i = 1; i <= N; ++i)
        ps[i] = (ps[i - 1] + xs[i]) % K;

    map<ll, ll> hs;
    ++hs[0];

    int last = 0;
    ll ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (i - last == K)
        {
            ll q = mod(ps[last] - last, K);
            hs[q]--;
            ++last;
        }

        ll r = mod(ps[i] - i, K);
        ans += hs[r];

#ifdef DEBUG
//    cout << "xs[" << i << "] = " << xs[i] << ", ps[" << i << "] = " << ps[i] << ", r = " << r << ", ans = " << ans << endl;
//    for (auto [x, v] : hs)
 //       cout << x << ": " << v << endl;
#endif
        hs[r]++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<ll> xs(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> xs[i];

    auto ans = solve(N, K, xs);

    cout << ans << '\n';

    return 0;
}
