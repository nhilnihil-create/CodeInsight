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
	string s1, s2;
	cin>>s1>>s2;
	int i=0, j=0;
	for(int i=0; i<n; i++)
	{
		cout<<s1[i]<<s2[i];	
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