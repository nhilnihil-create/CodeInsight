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
  string s;
  cin>>s;
  
  ll k;
  cin>>k;
  
  ll ans=0;
  
  ll n=s.size();
  if(s[0]!=s[n-1]){
      
      for(ll i=0;i<n;i++){
          ll j=i;
          while(j<n&&s[j]==s[i])j++;
          
          ll have=j-i;
          j--;
          i=j;
          ans+=have/2;
      }
      
      ans*=k;
      
  }
  else{
      ll c1=0;
      ll c2=0;
      
      for(ll i=0;i<n&&s[i]==s[0];i++)c1++;
      for(ll i=n-1;i>=0&&s[i]==s[n-1];i--)c2++;
      
      
      for(ll i=c1;i<n-c2;i++){
           ll j=i;
          while(j<n&&s[j]==s[i])j++;
          
          ll have=j-i;
          j--;
          i=j;
          ans+=have/2;
      }
      
      ans*=k;
      ans+=c1/2;
      ans+=c2/2;
      
      ans+=((c1+c2)/2)*(k-1);
      
      if(c1==c2&&c1==n){
          ans=(n*k)/2;
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