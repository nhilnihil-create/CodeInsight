#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		int f, t;
		cin >> f >> t;
		a[i] = f;
		b[i] = t;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (n % 2) {
		cout << b[n / 2] - a[n / 2] + 1;
	}
	else {
		cout << (b[n / 2 - 1] + b[n / 2]) - (a[n / 2 - 1] + a[n / 2]) + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << '\n';
	}
}