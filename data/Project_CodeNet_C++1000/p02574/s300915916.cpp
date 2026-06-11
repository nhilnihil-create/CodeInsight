#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

bool ok = false;
bool fact[1000006];
void factors(int x) {
	if (ok)
		return;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			int a = i, b = x / i;
			if (a == b) {
				a = i;
				b = 1;
			}
			if (a != 1) {
				if (fact[a]) {
					ok = true;
					return;
				}
				fact[a] = true;
			}
			if (b != 1) {
				if (fact[b]) {
					ok = true;
					return;
				}
				fact[b] = true;
			}
		}
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	memset(fact, false, sizeof fact);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int gcd = arr[0];
	factors(arr[0]);
	for (int i = 1; i < n; i++) {
		factors(arr[i]);
		gcd = __gcd(gcd, arr[i]);
	}
	if (!ok)
		cout << "pairwise coprime";
	else if (gcd == 1)
		cout << "setwise coprime";
	else
		cout << "not coprime";
	return 0;
}