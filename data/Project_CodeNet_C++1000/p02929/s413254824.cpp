#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll f(ll n)
{
    ll res = 1;
    for (ll i = n; i >= 1; i--)
    {
        (res *= i) %= MOD;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    string s;
    cin >> n >> s;
    vector<bool> check(2 * n, false);
    for (ll i = 0; i < 2 * n; i++)
    {
        if (i % 2 == 0 && s[i] == 'W')
        {
            check[i] = true;
        }
        if (i % 2 && s[i] == 'B')
        {
            check[i] = true;
        }
    }
    ll ans = 1;
    ll lsum = 0;
    for (ll i = 0; i < 2 * n; i++)
    {
        if (check[i])
        {
            if (lsum == 0)
            {
                cout << 0 << endl;
                return 0;
            }
            (ans *= lsum) %= MOD;
            lsum--;
        }
        else
        {
            lsum++;
        }
    }
    if (lsum > 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans * f(n) % MOD << endl;
    }
}