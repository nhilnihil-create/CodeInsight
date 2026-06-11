#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
typedef pair<ll, ll> pll;
#define pb push_back
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
ll inf = 1e18;
ll p = 1e9 + 7;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, y, x,  z, w, g, key, l, r, n, m, t, k, d;
    ll t2, t3, t4, t1;
    string s;
    cin >> n >> k;
    ll ans = -inf;
    ll p[n + 1], c[n + 1];
    for (i = 1; i <= n; i++)
        cin >> p[i];
    for (i = 1; i <= n; i++)
        cin >> c[i];
    for (i = 1; i <= n; i++)
    {
        t1 = c[i], t2 = k - 1, t3 = c[i], t4 = i;
        vector<ll>marked(n + 2, 0), val(n + 2, 0);
        marked[i] = 1;
        ll cur = 1;
        val[cur++] = c[i];
        while (t2 > 0)
        {

            if (marked[p[t4]] == 0)
            {
                t4 = p[t4];
                t3 += c[t4];
                t2--;
                marked[t4] = cur;
                val[cur++] = t3;
                t1 = std::max(t1, t3);
            }
            else
            {

                ll len = marked[t4] - marked[p[t4]] + 1;

                ll t6 = val[marked[t4]] - val[marked[p[t4]] - 1];
                //cout << val[1];
                ll t5 = t2 / len;
                if (t2 % len == 0)
                {
                    t5--;
                    t2 = len;
                }
                else
                    t2 %= len;
                t3 += t5 * t6;
                t1 = std::max(t1, t3);


                while (t2 > 0)
                {
                    t4 = p[t4];
                    t3 += c[t4];
                    t1 = std::max(t1, t3);
                    t2--;

                }
                break;



            }
        }
        ans = std::max(t1, ans);

    }
    cout << ans;







    return 0;
}