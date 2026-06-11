#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
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
#define N 1000001

int a[N]={0},b[N]={0};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,ans=0;
	cin>>n;
	vector<int> res(n);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[x]++;
		b[x]=1;
		res[i]=x;
	}
	for(int i=1;i<N;i++)
	{
		if(a[i]>1)
			b[i]=-1;
		for(int j=i+i;j<N;j+=i)
		{
			if(a[j]>0&&a[i]>0)
				b[j]=-1;
		}
	}
	for(int i=0;i<n;i++)
		if(b[res[i]]==1)
			ans++;
	cout<<ans;
	return 0;
}
