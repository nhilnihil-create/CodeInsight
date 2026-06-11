#include<bits/stdc++.h>
#define ll long long int
#define mk make_pair
#define pb push_back
#define INF (ll)1e18
#define pii pair<ll,ll>
#define mod 1000000007 //998244353
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>b;i--)
#define ff first
#define ss second
#define PI 3.141592653589793238
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>()>
using namespace std;
ll pow_mod(ll a,ll b)
{
	ll res=1;
	while(b!=0)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    
    string s[n];
    
    for(ll i=0;i<n;i++)
    cin>>s[i];
    
    ll row_r[n][m];
    
    ll row_l[n][m];
    
    ll col_r[n][m];
    
    ll col_l[n][m];
    
    ll row_left=-1;
    
    ll row_right=m;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            
            if(s[i][j]=='#')
            row_left=j;
            
            row_l[i][j]=row_left;
        }
        
        row_left=-1;
        
        for(ll j=m-1;j>=0;j--){
            if(s[i][j]=='#')
            row_right=j;
            
            row_r[i][j]=row_right;
        }
        
        row_right=m;
    }
    
    
    ll col_left=-1;
    
    ll col_right=n;
    ll ans=0;
    
    
      for(ll j=0;j<m;j++){
        for(ll i=0;i<n;i++){
            
            if(s[i][j]=='#')
            col_left=i;
            
            col_l[i][j]=col_left;
        }
        
        col_left=-1;
        
        for(ll i=n-1;i>=0;i--){
            if(s[i][j]=='#')
            col_right=i;
            
            col_r[i][j]=col_right;
        }
        
        col_right=n;
    }
    
    ll mx=0;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            
            if(s[i][j]=='.'){
                ll r= row_r[i][j]-row_l[i][j]+col_r[i][j]-col_l[i][j]-3;
                
               // cout<<row_l[i][j]<<" "<<row_r[i][j]<<" "<<col_l[i][j]<<" "<<col_r[i][j]<<endl;
                ans=max(ans,r);
            }
        }
    }
    
    cout<<ans<<endl;
}
int32_t main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
//Start from Here.

  ll t;
  t=1;
 // cin>>t;
  while(t--)
  solve();
  
//Good Bye!
    return 0;
}