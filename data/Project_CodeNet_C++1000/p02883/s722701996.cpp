#include<bits/stdc++.h>
using namespace std;
int a[200010], f[200010];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	sort(a + 1, a + 1 + n);
	sort(f + 1, f + 1 + n, greater<int>());
	long long l = 0, r = 1e12, answer = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long ch = 0;
		for (int i = 1; i <= n; ++i) {
			if (1LL * a[i] * f[i] > mid) {
				ch += ceil(((1.0L * a[i] * f[i]) - mid) / f[i]); 
			}
		}
		if (ch <= k) {
			answer = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << answer;
}