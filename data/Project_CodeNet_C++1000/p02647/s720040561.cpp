#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], b[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int times = 0; times < min(k, 500); times++) {
		for (int i = 0; i <= n + 1; i++) b[i] = 0;
		for (int i = 1; i <= n; i++) b[max(1, i - a[i])]++, b[min(n + 1, i + a[i] + 1)]--;
		a[0] = b[0];
		for (int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i];
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
	
	return 0;
}
