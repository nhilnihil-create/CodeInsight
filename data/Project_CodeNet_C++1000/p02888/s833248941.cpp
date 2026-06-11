#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	int ans = 0;
	for (int b = 1; b <= n - 2; b++) {
		int lb = l[b];
		for (int a = 0; a < b; a++) {
			int la = l[a];
			for (int c = b + 1; c < n; c++) {
				int lc = l[c];
				if (lc < la + lb) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}