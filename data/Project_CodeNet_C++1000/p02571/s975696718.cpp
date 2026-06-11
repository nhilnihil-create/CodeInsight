#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
using namespace std;

#define loop(i, x, y) for (i = x; i < y; i++)
#define loopr(i, x, y) for (i = x; i > y; i--)

//use *it instead of it
#define vloop(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define vloopr(it, x) for (auto it = x.end() - 1; it != x.begin() - 1; it--)

#define yes printf("YES\n")
#define no printf("NO\n")
#define pb push_back
#define mp make_pair

#define debug(x) cerr << #x << ":" << x << endl
#define yo cerr << "yo" << endl

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

#define test(t) \
    ll t;       \
    cin >> t;   \
    while (t--)

//use double
#define precision(x)       \
    cout.setf(ios::fixed); \
    cout << setprecision(10) << x << endl;

// ll gcd(ll x_f, ll y_f)
// {
//     if (x_f == 0)
//         return y_f;
//     return gcd(y_f % x_f, x_f);
// }

// ll power(ll x_f, ll y_f, ll m_f)
// {
//     ll res_f = 1;

//     x_f = x_f% m_f;
//     while (y_f)
//     {
//         if (y_f & 1)
//             res_f = (res_f * x_f) % m_f;
//         y_f = y_f >> 1;
//         x_f = (x_f * x_f) % m_f;
//     }
//     return res_f;
// }

// ll less(ll x_f, ll y_f)
// {
//     return (x_f > y_f) ? y_f : x_f;
// }
// ll more(ll x_f, ll y_f)
// {
//     return (x_f < y_f) ? y_f : x_f;
// }

ll fac(ll x_f)
{
    ll fac_f = 1;
    for (ll i = 1; i <= x_f; i++)
    {
        fac_f *= i;
        fac_f = fac_f % MOD;
    }
    return fac_f;
}

bool composite[1000007] = {false};
void seive(ll x)
{
    composite[0] = true;
    composite[1] = true;
    for (ll i = 2; i <= x; i++)
    {
        if (!composite[i])
        {
            for (ll j = 2 * i; j <= x; j += i)
            {
                composite[j] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;
    ll n, m;
    n = s.length();
    m = t.length();
    ll ans = m;
    for (ll i = 0; i <= n - m; i++)
    {
        ll diff = 0;
        for (ll j = 0; j < m; j++)
        {
            if (s[j + i] != t[j])
                diff++;
        }
        ans = min(ans, diff);
    }
    cout << ans << endl;
    return 0;
}