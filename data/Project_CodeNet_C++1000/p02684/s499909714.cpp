#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 1000000000000000
#define mod 1000000007
#define ld long double
#define pll pair<ll,ll>
using namespace std;
int main()
{ 
	fast;
	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	for(ll i=1;i<=n;i++)
	  cin>>a[i];
	ll up[n+1][61];
	memset(up,0,sizeof(up));
	for(ll i=1;i<=n;i++)
	  up[i][0]=a[i];
	for(ll j=1;j<61;j++)
	  for(ll i=1;i<=n;i++)
	    up[i][j]=up[up[i][j-1]][j-1];
	ll strt=1,ct=0;
	for(ll i=60;i>-1;i--)
	  if(ct+(1ULL<<i)<=k)
	    strt=up[strt][i],ct=ct+(1ULL<<i);
	cout<<strt;
	return 0;
}
