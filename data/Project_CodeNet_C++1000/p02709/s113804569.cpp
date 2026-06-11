#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ld long double
#define dd double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector<pll> vplll;
ll mod = 1e9+7;
const ld PI = 2 * acos(0.0);
const vector<ll> dx = {1, -1, 0, 0};
const vector<ll> dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
ll dp[2001][2001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,t,n,m,k,q; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        vector <pll> v;
        v.pb(mp(1e18,-1));
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.pb(mp(a,i+1));
        }
        sort(rbegin(v), rend(v));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll x = n-(i-j-1);
                x = v[i].ff*(abs(v[i].ss-x));
                dp[i][j] = max(dp[i][j], dp[i-1][j] + x);
                x = v[i].ff*(abs(v[i].ss-j-1));
                dp[i][j+1] = max(dp[i-1][j]+x,dp[i][j+1]);
            }
        }
        m = 0;
        for(int i=1;i<=n;i++)
            m = max(m,dp[n][i]);
        cout<<m<<endl;
    }
    return 0;
}