#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p, a, b) for (ll p = a; p < b; p++)
#define F first
#define S second
using namespace std;

typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;

int main()
{
    ll t, i, j, k, ans, n, m, sum = 0, x;

    //cin>>t;
    t = 1;
    while (t--)
    {
        cin>>n;
        ll cnt[10][10] = {0};

        rep(p,1,n+1)
        {
            ll l = p%10;

            k = p;
            while(k/10)k/=10;
            ll f = k;
            cnt[f][l]++;
        }

        ans=0;
        rep(p,1,10)
        {
            rep(q,0,10)
            {
                ans += (cnt[p][q] * cnt[q][p]);
            }
        }

        cout<<ans;
    }

    return 0;
}
