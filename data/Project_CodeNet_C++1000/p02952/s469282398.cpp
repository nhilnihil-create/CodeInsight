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
	int tCnt = 0;
	for(int i=1; i<=n; i++)
	{
		int cnt = 0;
		int temp = i;
		while(temp>0)
		{
			temp/=10;
			cnt++;
		}
//		cout<<i<<": "<<cnt<<"\n";
		if(cnt%2!=0)
			tCnt++;
	}
	cout<<tCnt<<"\n";
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