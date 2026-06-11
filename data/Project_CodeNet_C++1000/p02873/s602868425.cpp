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
	string s;
	cin>>s;
	vector<pair<char, int>> vect;
	int n = s.length();
	vector<int> ans(n+1);
	ll sum = 0;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='<')
			ans[i+1] = max(ans[i]+1, ans[i+1]);
	}
	for(int i=n-1; i>=0; i--)
	{
		if(s[i]=='>')
			ans[i] = max(ans[i], ans[i+1]+1);
	}
	for(auto a: ans)
		sum+=a;
	cout<<sum<<"\n";
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