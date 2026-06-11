#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S, T;
	cin >> S >> T;

	int ans = 10000;
	for (int i = 0; i < S.size() - T.size() + 1; ++i) {
		int cnt = 0;
		for (int j = 0; j < T.size(); ++j) {
			if (T[j] != S[i + j]) {
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}

	cout << ans << endl;
	return 0;
}
