#include <bits/stdc++.h>
using namespace std;

int a[1000005], f[1000005];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
	    char c;
	    cin >> c;
	    a[i] = c - '1';
	}

	f[0] = 0;
	for (int i = 0; i < N; ++i) f[i + 1] = __builtin_ctz(i + 1) + f[i];

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += a[i] * (f[N - 1] == f[i] + f[N - i - 1]);
	}
	if (ans % 2) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		if (a[i] == 1) {
			cout << 0 << '\n';
			return 0;
		}	
	}
	ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += (a[i] / 2) * (f[N - 1] == f[i] + f[N - i - 1]);
	}
	cout << 2 * (ans % 2) << '\n';
}