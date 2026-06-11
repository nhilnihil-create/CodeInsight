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
#define srt(v)  if(!v.empty())sort(v.begin(),v.end())
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
  ll n;
  cin>>n;
  
  ll a[n+1][n];
  
  for(ll i=1;i<=n;i++){
      for(ll j=1;j<n;j++)
      cin>>a[i][j];
  }
  
  ll ptr[n+1];
  
  for(ll i=1;i<=n;i++)
  ptr[i]=1;
  
  ll ans=0;
  
  while(true){
      ll cnt=0;
      
      bool mark[n+1];
      
      memset(mark,false,sizeof(mark));
      
      for(ll i=1;i<=n;i++){
        if(mark[i])
        continue;
        
        if(ptr[i]<n&&ptr[a[i][ptr[i]]]<n&&mark[i]==false&&mark[a[i][ptr[i]]]==false&&(i==a[a[i][ptr[i]]][ptr[a[i][ptr[i]]]]))
        {
            cnt++;
            //ptr[i]++;
            //if(i==1)
            //cout<<i<<" "<<a[i][ptr[i]]<<endl;
            mark[i]=true;
            mark[a[i][ptr[i]]]=true;
            
            ptr[a[i][ptr[i]]]++;
            ptr[i]++;
            
            
        }
        
      }
      
      
     // cout<<cnt<<endl;
      if(cnt==0)
      break;
      
      ans++;
  }
  
  for(ll i=1;i<=n;i++){
      if(ptr[i]<n){
          cout<<"-1\n";
          return;
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