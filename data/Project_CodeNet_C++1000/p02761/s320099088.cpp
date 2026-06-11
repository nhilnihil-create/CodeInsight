#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<int> s(m);
	vector<char> c(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> c[i];
	}
	int tmp_n = n;
	int u = 1; while (tmp_n--) {u *= 10;}
	int ans = -1;
	for (int i = 0; i < u; i++) {
		string si = to_string(i);
		if (si.size() != n) continue;
		bool ok = true;
		for (int j = 0; j < m; j++) {
			if (!(si[s[j] - 1] == c[j])) {
				ok = false;
			}
		}
		if (ok) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}