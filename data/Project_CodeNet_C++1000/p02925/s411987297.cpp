#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mx *max_element
#define mn *min_element
#define fo(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define rfo(i,n) for(ll i=n-1;i>=0;i--)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define precision cout<<fixed<<setprecision(10)
#define mem(x,p) memset(x,p,sizeof(x))
#define w(t) ll t;cin>>t;while(t--)
#define kk "\n"
#define setbits(x) __builtin_popcountll(x)
const double pi=3.1415926535897932384626;
//const ll mod = 998244353;
const ll mod=1e9+7;
int main()
{
  IOS
  ll n;
  cin>>n;
  ll a[n][n-1];
  fo(i,n)
  {
  	fo(j,n-1)
  	cin>>a[i][j];
  }
  vector <pair<ll,ll>> loc(n,{0,0});
  ll ans=0;
  while(1)
  {
  	ll f=0;
  	fo(i,n)
  	{
  		ll r=a[i][loc[i].fi]-1;
  		if(r<n&&a[r][loc[r].fi]-1==i&&loc[i].se!=-1&&loc[r].se!=-1)
  		{
  			loc[i].fi++;
  			loc[i].se=-1;
  			loc[r].fi++;
  			loc[r].se=-1;
  			f=1;
  		}
  	}
  	if(f)
  	{
  		ans++;ll g=0;
  		fo(i,n)
  		{
  			if(loc[i].fi<n-1)
  			{
  				g=1;
  				break;
  			}
  		}
  		if(!g)
  			break;
  		fo(i,n)
  		loc[i].se=0;
  	}
  	if(!f)
  	{
  		cout<<-1;
  		return 0;
  	}
  }
  cout<<ans;
  return 0;
}