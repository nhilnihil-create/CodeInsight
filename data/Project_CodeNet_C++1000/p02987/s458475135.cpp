// ABC_132_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	string s;
	cin >> s;

	map<char, int> mp;

	forn(i, s.size()) ++mp[s[i]];

	bool flag = false;
	for(auto item : mp) {
		if(item.second == 2) {
			flag = true;
			continue;
		}
		else {
			flag = false;
			break;
		}
	}

	if(flag) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}