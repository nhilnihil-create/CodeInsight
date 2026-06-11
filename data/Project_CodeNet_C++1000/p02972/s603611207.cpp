#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(int x) {
	if (x % 2 == 0) return 0;
	else return 1;
}

int main() {

	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> b(n + 1, 0);
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		int sum = 0; // 0 or 1
		for (int j = i + i; j <= n; j += i) {
			sum += b[j];
		}
		sum = func(sum);
		if (sum != a[i]) {
			b[i] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1) cout << i << " ";
	}
	cout << endl;
	return 0;
}