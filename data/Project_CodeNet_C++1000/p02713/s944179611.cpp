#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long res = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			for (int c = 1; c <= n; ++c) {
				res += gcd(a, gcd(b, c));
			}
		}
	}
	cout << res << '\n';
	return 0;
}