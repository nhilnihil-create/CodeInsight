#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> p(n),q(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		q[i] = i + 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] != q[i]) cnt++;
	}
	if (cnt <= 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}