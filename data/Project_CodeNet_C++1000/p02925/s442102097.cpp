#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1000;

int main() {
	int n;
	cin >> n;
	vector<queue<int>> v(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			int a;
			cin >> a;
			a--;
			v[i].push(a);
		}
	}
	bool cont = true;
	int ans = 0;
	while (cont) {
		ans++;
		cont = false;
		bool b[MAX] = {};
		for (int i = 0; i < n; i++) {
			if (v[i].empty()) continue;
			int p = v[i].front();
			if (b[p] || b[i]) continue;
			if (v[p].front() == i) {
				v[i].pop(); v[p].pop();
				b[i] = b[p] = true;
				cont = true;
			}
		}
	}
	ans--;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (!v[i].empty()) ok = false;
	}
	if (ok) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}