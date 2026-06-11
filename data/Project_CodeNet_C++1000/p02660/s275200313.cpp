#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define float long double
#define pb push_back
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pq priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define prdec(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define mii map<int,int>
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX
int exp(int x,int y,int mod){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int modinv(int x,int mod){return exp(x,mod-2,mod);}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,ans=0;
	cin>>n;
	mii m;
	while(n%2==0)
	{
		n/=2;
		m[2]++;
	}
	for(int j=3;j*j<=n;j+=2)
	{
		while(n%j==0)
		{
			n/=j;
			m[j]++;
		}
	}
	if(n>2)
		m[n]++;
	for(auto x:m)
	{
		int i=1;
		for(i=1;;i++)
		{
			int val=(i*(i+1))/2;
			if(val>x.se)
				break;
		}
		--i;
		ans+=i;
	}
	cout<<ans;
	return 0;
}
