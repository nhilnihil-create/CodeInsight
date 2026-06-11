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
	int cnt = 0;
	vector<int> vect(n+1);
	for(int i=1; i<=n; i++)
		cin>>vect[i];
	for(int i=2; i<n; i++)
	{
		if(vect[i]>vect[i-1] && vect[i]<vect[i+1])
			cnt++;
		if(vect[i]>vect[i+1] && vect[i]<vect[i-1])
			cnt++;
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