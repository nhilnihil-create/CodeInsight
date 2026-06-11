#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;
ll NC2(ll n)
{
	return n*(n-1)/2;
}
void solve()
{
	int n;
	cin>>n;
	map<vector<int>, ll> mp;
	string s;
	ll cnt = 0;
	REP(i,n)
	{
		cin>>s;
		vector<int> v(26, 0);
		REP(j, s.length())
		{
			v[s[j]-'a']++;
		}
		mp[v]++;
	}
	for(auto m:mp)
	{
		if(m.second>1)
			cnt+=NC2(m.second);
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