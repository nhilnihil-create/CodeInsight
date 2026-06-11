#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ans(n + 1, 0);
	for (int i = n; i >= 1 ; i--) {
		int tmpSum = 0;
		for (int j = i + i; j <= n; j += i) {
			tmpSum += ans[j];
		}
		if (tmpSum % 2 != a[i]) {
			ans[i] = 1;
		}
	}
	vector<int> b;
	for (int i = 1; i <= n; i++) {
		if (ans[i]) b.push_back(i);
	}
	cout << b.size() << endl;
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	return 0;
}