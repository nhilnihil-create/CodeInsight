#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define mod 1000000007
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<n;i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ms(v,n) memset((v),n,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define nl endl
#define inf 1e18
#define cases ll t;cin>>t;while(t--)
#define BLOCK 500
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;

const int N=2005;

ll dp[N][N],vis[N][N];
ll n,m;
 ll a[N],b[N];
ll go(ll i,ll j)
{
    if(i>=n||j>=m)
    return 0;

    ll &ans=dp[i][j];

    if(vis[i][j])
    return ans;

    vis[i][j]=1;
    if(a[i]==b[j])
    ans=1+go(i+1,j)+go(i,j+1);

    else
    {
    ans=go(i,j+1)+go(i+1,j);
    if(ans>=mod)
    ans-=mod;
    ans-=go(i+1,j+1);
    if(ans<0)
    ans+=mod;


    }
    

    if(ans>=mod)
    ans-=mod;

    return ans;


    
}

int main()
{
    
    fast

    
    cin>>n>>m;
   
    
    f(i,n)
    cin>>a[i];
    f(i,m)
    cin>>b[i];

    //cout<<go(0,0)+1;

    
f1(i,n+1)
f1(j,m+1)
{
    
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            dp[i][j] = (dp[i][j] - dp[i - 1][j - 1] + mod) % mod;
            if (a[i-1] == b[j-1]) {
                dp[i][j] = (dp[i][j] + 1 + dp[i - 1][j - 1]) % mod;
            }


}
cout<<(dp[n][m]+1)%mod;


// ll ans=0;
// f1(i,n+1)
// f1(j,m+1)
// {
//     ans+=dp[i][j];
//     if(ans>=mod)
//     ans-=mod;
// }

// cout<<ans;

    
   


    

       
    return 0;
    
}

