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
	map<int, int> mp;
	int dec = 0;
	int n, k, q, x;
	cin>>n>>k>>q;
	REP(i,q)
	{
		cin>>x;
		mp[x]++;
		dec++;
	}
	for(int i=1; i<=n;i++)
	{
		if(k-dec+mp[i]>0)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
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