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
#define PI         2*acos(0.0);
#define lb         lower_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define btpc       __builtin_popcountll
#define spc(x)     cout<<fixed<<setprecision(x)

const   long long  cs=2e5+5;
const   long long  inf=1e18;
const   long long  mod=1e9+7;
void solve()
{
    int64_t t,n,m,a,b,d,e,i,j,k,x,y,cnt=1,cnt1=0;
    bool flag = false;

    cin>>n;
    x=n;
    string s;
    vector<string>v;
    while(n--)
    {
        cin>>s;
        sort(all(s));
        v.pb(s);
    }
    sort(all(v));
    lve v1;cnt=1;
    for(i=0;i<x-1;i++)
    {
        if(v[i]==v[i+1]) cnt++;
        else {
            v1.pb(cnt);
            cnt=1;
        }
    }
    v1.pb(cnt);
    cnt=0;
    for(ll ss:v1)
    {
        cnt+=(ss*(ss-1))/2;
    }
    cout<<cnt<<endl;

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