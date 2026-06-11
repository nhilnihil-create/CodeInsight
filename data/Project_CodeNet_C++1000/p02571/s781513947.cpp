#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, t; cin >> s >> t;
	int sLen = s.length();
	int tLen = t.length();
	int ans = tLen;
	for(int pos = tLen-1; pos < sLen; ++pos)
	{
		int changes = 0;
		for(int i = 0; i < tLen; ++i)
		{
			changes += (s[pos-i] != t[tLen-1-i]) ? 1 : 0;
		}
		ans = min(ans, changes);
	}
	cout << ans;
	return 0;
}