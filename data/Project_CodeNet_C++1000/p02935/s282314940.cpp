#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long>lve;
typedef vector<pair<ll,ll> > lvp;

#define sp         ' '
#define endl       '\n'
#define F          first
#define S          second
#define pp         pop_back`
#define pb         push_back
#define mp         make_pair 
#define GCD(x,y)   __gcd(x,y)
#define lb         lower_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define btpc       __builtin_popcountll
#define spc(x)     cout<<fixed<<setprecision(x)

const   long long  inf = 1e18;
const   long long  cs =  200005;
const   long long  mod = 1000000007;
const   double     PI =  2 * acos(0.0);
void solve()
{
    long long t,n,m,a,b,i,j,k,x,y,cnt=1;
    bool flag = false;
    cin>>n;
    lve v(n);
    for(auto &ss:v) cin>>ss;
    sort(all(v));
    double ans = v[0];
    for (i = 1; i < n; i++){
        ans = (ans + v[i]) / 2.0;
    }
    cout << ans << endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    // freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);

    // ll tc;
    // cin>>tc;
    // while(tc--)
    solve();

    return 0;
}