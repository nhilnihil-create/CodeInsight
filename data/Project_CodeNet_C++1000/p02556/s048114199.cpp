// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 200005; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{
    ll n;
    cin >> n;
    pll p[n];
    for(ll i=0;i<n;i++)   cin >> p[i].ff >> p[i].ss;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        v.pb(p[i].ff+p[i].ss);
    }
    sort(all(v));
    ll ans = v[n-1] - v[0];
    v.clear();
    for(ll i=0;i<n;i++)
    {
        v.pb(p[i].ff+p[i].ss);
    }
    sort(all(v));
    ans = max(v[n-1] - v[0],ans);
    v.clear();
    for(ll i=0;i<n;i++)
    {
        v.pb(p[i].ss-p[i].ff);
    }
    sort(all(v));
    ans = max(ans,v[n-1] - v[0]);
    cout<<ans<<"\n";
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}