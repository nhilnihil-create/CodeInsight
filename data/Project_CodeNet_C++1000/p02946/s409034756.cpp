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
	int k, x;
	cin>>k>>x;
	int start = max(-1000000, x-k+1);
	int end = min(1000000, x+k-1);
	for(int i=start; i<=end; i++)
	{
		cout<<i<<" ";
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