#include <bits/stdc++.h>
using namespace std;

int a[1 << 20], b[1 << 20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int times = 0; times < min(k, 1000); times++) {
		for (int i = 1; i <= n; i++) b[i] = 0;
		for (int i = 1; i <= n; i++) {
			b[max(1, i - a[i])]++;
			b[min(n, i + a[i]) + 1]--;
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			now += b[i];
			a[i] = now;
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
	return 0;
}

