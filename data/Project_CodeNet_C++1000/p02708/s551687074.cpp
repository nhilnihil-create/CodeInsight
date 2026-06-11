#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k, ans = 0;
	cin >> n >> k;
	for (long long i = k; i <= n + 1; i++) {
		ans += (n - i + 1) * i + 1;
		ans %=1000000007;
	}
	cout << ans;
}
