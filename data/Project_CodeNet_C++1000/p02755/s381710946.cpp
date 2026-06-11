#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A, B; cin >> A >> B;
	for (int i = 0; i <= 1000; i++) {
		if (i * 8 / 100 == A && i / 10 == B) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}