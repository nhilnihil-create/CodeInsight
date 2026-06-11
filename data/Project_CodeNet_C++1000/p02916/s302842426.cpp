#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;

void solve()
{
	int n;
	cin>>n;
	ll ans = 0;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	REP(i, n)
	{
		cin>>a[i];
	}
	REP(i,n)
		cin>>b[i];
	REP(i,n-1)
		cin>>c[i];
	int prev = -1;
	REP(i,n)
	{
		if(i+1<n && a[i]+1==a[i+1])
			ans+=c[a[i]-1];
		ans+=b[a[i]-1];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}