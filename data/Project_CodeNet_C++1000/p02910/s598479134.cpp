#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	string s; cin >> s;
	string ans = "Yes\n";
	rep(i, s.size())
	{
		if (i%2 && s[i] == 'R')
		{
			ans = "No\n";
			break;
		}
		if (i % 2 == 0 && s[i] == 'L')
		{
			ans = "No\n";
			break ;
		}
	}
	cout << ans;
	return (0);
}
