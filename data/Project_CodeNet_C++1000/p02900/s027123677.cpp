#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

vector<pair<ll, ll>> prime_factorize(ll n)
{
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; ++a)
    {
        if (n % a != 0)
            continue;
        ll ex = 0;

        while (n % a == 0)
        {
            ++ex;
            n /= a;
        }
        res.push_back({a, ex});
    }
    if (n != 1)
        res.push_back({n, 1});
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    const auto &res_a = prime_factorize(a);
    const auto &res_b = prime_factorize(b);
    ll ans = 0;
    map<ll, int> m;
    for (auto itr = res_a.begin(); itr != res_a.end(); itr++)
    {
        m[itr->first]++;
    }
    for (auto itr = res_b.begin(); itr != res_b.end(); itr++)
    {
        if (m[itr->first] == 1)
        {
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}