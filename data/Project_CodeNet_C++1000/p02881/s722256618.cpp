#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	cin >> n;
	long long ans = 1e15;
	for (int i=1; i<=sqrt(n); i++) {
		if (n % i == 0) {
			ans = min(ans, i + (n / i));
		}
	}
	cout << ans - 2 << '\n';
}