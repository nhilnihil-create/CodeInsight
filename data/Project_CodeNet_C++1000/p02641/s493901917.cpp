#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x, n; cin >> x >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	int tmp = 1000000;
	int ans;
	for (int i = 102; i >= -2 ; i--) {
		bool skip = false;
		for (int j = 0; j < n; j++) {
			if (i == p[j]) skip = true;
		}
		if (skip) continue;
		if (abs(x - i) <= tmp) {
			tmp = abs(x - i);
			ans = i;
		}
	}
	cout << ans << endl;
    return 0;
}