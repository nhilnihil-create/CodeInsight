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
	int len;
	cin>>len;
	string s;
	cin>>s;
	if(len&1)
	{
		cout<<"No\n";
		return;	
	}	
	int i = 0, j = len/2;
	while(j<len)
	{
		if(s[i]!=s[j])
		{
			cout<<"No\n";
			return;
		}
		i++, j++;
	}
	cout<<"Yes\n";
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