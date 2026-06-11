#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define ll long long
#define pp pair<ll,ll>
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
ll max(ll x, ll y)
{
    return x>y ? x : y;
}
ll min(ll x, ll y)
{
    return x<y ? x : y;
}
ll _(ll&a , ll b)
{
    a=(a%mod+b%mod)%mod;
    a=(a+mod)%mod;
    return a;
}
ll dp2[100010],dp3[100010];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);dp2[0]=dp3[0]=1;ll tot=0;
    for(ll i=1;i<100010;i++)
    {
    	dp2[i]=(dp2[i-1]*2)%mod;
    	dp3[i]=(dp3[i-1]*3)%mod;
    }
    string l;cin >> l;
    for (int i = 0; i < l.size(); ++i)
    {
    	if(l[i]=='1')tot++;
    }
    ll ans=0;
    ll d=0;
    for (int i = 0; i < l.size(); ++i)
    {
    	if(l[i]=='1')
    	{
    		_(ans,((dp2[d]%mod)*(dp3[l.size()-i-1]%mod))%mod);
    		d++;
    	}
    }
    cout << (ans+dp2[tot])%mod;
    }