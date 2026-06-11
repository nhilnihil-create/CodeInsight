#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000;
const ll mod = 1000000007;
ll res[12345678], aa[1234][1234], bb[1234][1234];
ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
char maze[1234][1234];
signed main() {
	ll n, m, a = 0, b = 0, ans = 0; cin >> n;
	vector<ll> test(n), aaa;
	for (int h = 0; h < n; h++) { 
		cin >> test[h]; ans += abs(test[h]);
		if (test[h] > 0) { a++; }
		if (test[h] < 0) { b++; }
	}
	sort(test.begin(), test.end());
	if (n == 2) { cout << test[1] - test[0] << endl; cout << test[1] << ' ' << test[0] << endl; return 0; }
	if (a != 0 && b != 0) {
		cout << ans << endl;
		if (test[n - 2] < 0) {
			reverse(test.begin(), test.end());
			for (int h = 0; h < n - 1; h++) {
				cout << test[h] << ' ' << test[h + 1] << endl;
				test[h + 1] = test[h] - test[h + 1];
			}
			return 0;
		}
		for (int h = 0; h < n - 2; h++) {
			if (test[h] < 0 && test[h + 1] < 0) { aaa.push_back(test[h]); }
			else {
				cout << test[h] << ' ' << test[h + 1] << endl;
				if (h == n - 3) { aaa.push_back(test[h] - test[h + 1]); }
				test[h + 1] = test[h] - test[h + 1];
			}
		}
		aaa.push_back(test[n - 1]); reverse(aaa.begin(), aaa.end());
		for (int h = 0; h < aaa.size() - 1; h++) {
			cout << aaa[h] << ' ' << aaa[h + 1] << endl;
			aaa[h + 1] = aaa[h] - aaa[h + 1];
		}
	}
	if (b == 0) {
		ans -= test[0] + test[0];
		cout << ans << endl;
		for (int h = 2; h < n; h++) {
			cout << test[0] << ' ' << test[h] << endl;
			test[0] = test[0] - test[h];
		}
		cout << test[1] << ' ' << test[0] << endl;
	}
	else if (a == 0) {
		reverse(test.begin(), test.end());
		ans += test[0] + test[0];
		cout << ans << endl;
		for (int h = 2; h < n; h++) {
			cout << test[0] << ' ' << test[h] << endl;
			test[0] = test[0] - test[h];
		}
		cout << test[0] << ' ' << test[1] << endl;
	}
	return 0;
}