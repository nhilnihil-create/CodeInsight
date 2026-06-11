#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	int ans = 1;
	cin >> s;
	for (int i=1; i<s.size(); i++) {
		if (s[i] == '-') continue;
		if (s[i-1] == '-' || s[i-1] != s[i]) {
			ans ++;
		} else {
			if (i == s.size()-1) break;
			s[i+1] = '-';
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
