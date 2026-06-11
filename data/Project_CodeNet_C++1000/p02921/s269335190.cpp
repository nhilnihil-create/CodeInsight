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
#define up         upper_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define spc(x)     cout<<fixed<<setprecision(x)

const   long long  inf = 1e18;
const   long long  cs =  200005;
const   long long  mod = 1000000007;
const   double     PI =  2 * acos(0.0);
void solve()
{
    ll t,n,m,a,b,c,d,e,i,j,k,x,y,z,cnt=0,cnt1=0;
    bool flag = false;   
    
    string s,s1;
    cin>>s>>s1;
    for(i=0;i<3;i++)
    {
        if(s[i]==s1[i]) cnt++;
    }
    cout<<cnt<<endl;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    // freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);

    // int32_t tc;
    // cin>>tc;
    // while(tc--)
    solve();

    return 0;
}
