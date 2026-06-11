#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int  main()
{
	string s; cin >> s;
	map <char, int> mp;
	rep(i, s.size())
		mp[s[i]]++;
	if (mp.size() == 2)
	{
		if (mp[s[0]] == 2 && mp[s[1]] == 2 && mp[s[2]] == 2)
		{
			cout << "Yes\n"; return 0;
		}
	}
	cout << "No\n";
	return 0;
}
