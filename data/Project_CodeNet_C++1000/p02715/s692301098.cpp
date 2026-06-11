#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

ll dp[N],n,k;
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve()
{
    cin>>n>>k;
    ll ans=0;
    ll x=0;
    for(int i=k;i>0;i--)
    {
        dp[i]=expo((k/i),n,hell);
        x=0;
        for(int j=2*i;j<=k;j+=i)
        {
            x=(x+dp[j])%hell;
        }
        dp[i]=(dp[i]-x+hell)%hell;
    }
    rep(i,1,k+1)
    {
        ans=(ans+(i*dp[i])%hell)%hell;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}