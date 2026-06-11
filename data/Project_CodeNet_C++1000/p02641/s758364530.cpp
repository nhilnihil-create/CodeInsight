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


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x,ans=inf,y=1;
	cin>>x>>n;
	set<int> s;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<=101;i++)
	{
		if(s.count(i)==0)
		{
			if(abs(x-i)<ans)
			{
				ans=abs(x-i);
				y=i;
			}
		}
	}
	cout<<y;
	return 0;
}
