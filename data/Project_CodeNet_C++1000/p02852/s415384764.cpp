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
  ll n,m;
  
  cin>>n>>m;
  
  string s;
  
  cin>>s;
  
  vector<ll>ans;
  
  
  set<ll>st;
  
  for(ll i=0;i<n;i++){
      if(s[i]=='0')
      st.insert(i);
  }
  
  ll i=n;
  
 // ans.pb(n);
  
  while(true){
      auto it=st.lower_bound(i-m);
      
      if(it==st.end()){
          break;
      }
      
      
      ll l=*it;
      
      if(l>=i)
      break;
      
      ans.pb(i-l);
      
      i=*it;
  }
  
  if(i!=0)
  {
      cout<<"-1\n";
      return;
  }
  
  
  reverse(ans.begin(),ans.end());
  
  
  for(ll i=0;i<ans.size();i++)
  cout<<ans[i]<<" ";
  
  cout<<endl;
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