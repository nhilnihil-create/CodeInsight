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
        ll mi = LLONG_MAX;
        ans=1;

        cin>>x;mi = x;
        rep(p,1,n)
        {
            cin>>x;
            if(x<=mi)
            {
                mi = x;
                ans++;
            }
        }
        cout<<ans;
    }

    return 0;
}
