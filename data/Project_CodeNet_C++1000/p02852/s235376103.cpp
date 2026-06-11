#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N, M;
	string s;
	cin >> N >> M >> s;

	int now = N;
	set<int> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') { st.insert(i); }
	}
	vector<int> ans;
	while (now > 0) {
		int target = *st.lower_bound(now - M);
		if (target >= now) {
			cout << "-1\n";
			return 0;
		}
		ans.push_back(now - target);
		now = target;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
	}

	return 0;
}
