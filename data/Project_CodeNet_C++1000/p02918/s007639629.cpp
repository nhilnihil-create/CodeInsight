#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	pair<int, char> t;
	char prev = s[0];
	int cnt = 0, now = 0;
	vector<int> l, r;
	for (int i = 0; i < n; i++)
	{
		if(prev == s[i]) {
			cnt++;
		}
		else {
			l.push_back(cnt);
			now += cnt - 1;
			cnt = 1;
			prev = s[i];
		}
	}
	l.push_back(cnt);
	now += cnt - 1;

	now += 2 * min(k, ((int)l.size() - 1) / 2);
	k -= min(k, ((int)l.size() - 1) / 2);
	if(k > 0 && l.size() % 2 == 0) now++;
	cout << now << endl;
	return 0;
}

