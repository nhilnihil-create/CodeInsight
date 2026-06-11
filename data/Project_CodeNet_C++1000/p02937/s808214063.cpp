#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	vector<vector<int>> a(26);
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a'].emplace_back(i + 1);
	}

	for (int i = 0; i < t.length(); i++) {
		if (a[t[i] - 'a'].empty()) {
			cout << -1 << endl;
			return 0;
		}
	}

	int now = 0;
	long long ans = 0;
	for (int i = 0; i < t.length(); i++) {
		int spot = lower_bound(a[t[i] - 'a'].begin(), a[t[i] - 'a'].end(), now + 1) - a[t[i] - 'a'].begin();
		if (spot == a[t[i] - 'a'].size()) {
			ans += s.length() - now;
			ans += a[t[i] - 'a'][0];
			now = a[t[i] - 'a'][0];
		} else {
			ans += a[t[i] - 'a'][spot] - now;
			now = a[t[i] - 'a'][spot];
		}
	}
	cout << ans << endl;

	return 0;
}