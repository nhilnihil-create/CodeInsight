#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ball(n + 1, 0);
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		int tmp = 0;
		for (int j = i + i; j <= n; j += i) {			
			tmp += ball[j];
		}
		if (tmp % 2 != a[i]) {
			ball[i] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (ball[i] == 1) cout << i << endl;
	}
	return 0;
}