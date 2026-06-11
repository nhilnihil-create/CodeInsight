#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;
	if (s.length() == 1) {
		cout << n / 2 << endl;
		return 0;
	}

	vector<pair<char, long long>> p;
	p.emplace_back(make_pair(s[0], 1));
	for (int i = 1; i < s.length(); i++) {
		if (p[p.size() - 1].first != s[i]) {
			p.emplace_back(make_pair(s[i], 1));
		}
		else {
			p[p.size() - 1].second++;
		}
	}

	long long ans = 0;
	if (p.size() == 1) {
		ans = p[0].second * n / 2;
	}
	else if (p[0].first == p[p.size() - 1].first) {
		ans = (p[p.size() - 1].second + p[0].second) / 2 * (n - 1);
		ans += p[0].second / 2 + p[p.size() - 1].second / 2;
		for (int i = 1; i < p.size() - 1; i++) {
			ans += p[i].second / 2 * n;
		}
	}
	else {
		for (int i = 0; i < p.size(); i++) {
			ans += p[i].second / 2 * n;
		}
	}
	cout << ans << endl;

	return 0;
}