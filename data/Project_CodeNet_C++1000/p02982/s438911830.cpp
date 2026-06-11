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
	int n, d, cnt = 0;
	cin>>n>>d;
	vector<vector<int>> vect(n, vector<int>(d));
	REP(i, n)
	{
		REP(j, d)
			cin>>vect[i][j];
	}
	for(int i=0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			int sq = 0;
			for(int k = 0; k<d; k++)
			{
				sq += (vect[i][k]-vect[j][k])*(vect[i][k]-vect[j][k]);
			}
			float squareR = sqrt(sq*1.0);
			if(abs(squareR-int(squareR))==0)
				cnt++;
		}
	}
	cout<<cnt<<"\n";
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