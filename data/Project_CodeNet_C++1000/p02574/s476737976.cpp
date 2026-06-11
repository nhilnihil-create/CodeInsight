#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

const int MAX_A = 1e6;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve_test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int g = 0;
	for (int i = 0; i < n; i++)
		g = gcd(g, a[i]);
	if (g != 1) {
		cout << "not coprime\n";
		return;
	}

	vector<int> count(MAX_A + 1);
	for (int i = 0; i < n; i++)
		count[a[i]]++;

	vector<bool> prime(MAX_A + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= MAX_A; i++)
		if (prime[i]) {
			int total = 0;
			for (int j = i; j <= MAX_A; j += i) {
				prime[j] = false;
				total += count[j];
			}
			if (total > 1) {
				cout << "setwise coprime\n";
				return;

			}
		}

	cout << "pairwise coprime\n";
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
