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
	int n, maxCnt = 0;
	cin>>n;
	vector<int> v(n);
	REP(i,n)
		cin>>v[i];
	int i = 0;
	while(i<n)
	{
		int cnt = 0;
		while(i+1<n && v[i]>=v[i+1])
		{
			i++;
			cnt++;
		}
		maxCnt = max(maxCnt, cnt);
		i++;
	}
	cout<<maxCnt<<"\n";
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