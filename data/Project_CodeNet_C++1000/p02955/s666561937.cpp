#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

vector<ll> divisors(ll n)
{
    vector<ll> ds;

    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i)
            continue;

        ds.push_back(i);

        ll k = n / i;

        if (k != i)
            ds.push_back(k);
    }

    sort(ds.begin(), ds.end(), greater<ll>());

    return ds;
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll cost(ll y, const vector<ll>& xs)
{
    const ll oo { 1LL << 62 };
    ll c = 0, last = 0;

    vector<ll> rs(xs.size());

    for (size_t i = 0; i < xs.size(); ++i)
        rs[i] = xs[i] % y;

    sort(rs.begin(), rs.end());

    int L = 0, R = xs.size() - 1;

    while (L <= R)
    {
        if (last <= 0)
        {
            c += rs[L];
            last += rs[L++]; 
        } else
        {
            last -= (y - rs[R--]);
        }
    }

    return last ? oo : c;
}

ll solve(ll, ll K, const vector<ll>& xs)
{
    ll sum = 0, d = xs[0];
    
    for (auto x : xs)
    {
        sum += x;
        d = gcd(d, x);
    }

    auto ys = divisors(sum);

    for (auto y : ys)
    {
        auto c = cost(y, xs);
#ifdef DEBUG
cout << "y = " << y << ", c = " << c << endl;
#endif
        if (c <= K)
            return y;
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, K, xs);

    cout << ans << '\n';

    return 0;
}
