#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	b = a;
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) ans++;
	}
	if (ans <= 2) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
