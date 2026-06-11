// In the name of God

#include <bits/stdc++.h>

using namespace std;

vector<int> v[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for(int i = 0; i < n; i++) {
		if(s[i] == 'R') v[0].push_back(i);
		if(s[i] == 'G') v[1].push_back(i);
		if(s[i] == 'B') v[2].push_back(i);
	}

	auto solve = [&](vector<int> &v1, vector<int> &v2, vector<int> &v3) {
		// take i, j from v1 and v2
		// take k from v3
		long long ret = 0;
		for(int i : v1) {
			for(int j : v2) {
				if(j < i) continue;
				ret += v3.end() - lower_bound(v3.begin(), v3.end(), j);
				if(j + (j - i) < n && s[j + (j - i)] != s[j] && s[j + (j - i)] != s[i]) ret--;
			}
		}
		return ret;
	};

	long long ans = 0;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(i == j) continue;
			ans += solve(v[i], v[j], v[3 - i - j]);
		}
	}

	cout << ans;
	

	return 0;
}
