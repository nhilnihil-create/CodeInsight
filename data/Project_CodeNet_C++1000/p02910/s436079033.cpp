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
	bool isPos = 1;
	REP(i, s.length())
	{
		int pos = i+1;
//		cout<<pos<<" char: "<<s[i]<<"\n";
		if(pos%2==0)
		{
//			cout<<i+1<<" is LUD -> "<<s[i]<<"\n";
			if(s[i]!='L' && s[i]!='U' && s[i]!='D')
			{
				isPos = 0;
				break;
			}
		}
		else
		{
//			cout<<i+1<<" is RUD -> "<<s[i]<<"\n";
			if(s[i]!='R' && s[i]!='U' && s[i]!='D')
			{
				isPos = 0;
				break;
			}
		}
	}
	if(isPos)
		cout<<"Yes\n";
	else
		cout<<"No\n";
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