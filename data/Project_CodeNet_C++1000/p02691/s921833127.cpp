#include <bits/stdc++.h>

using namespace std;

long n, ans;
map<long, long> x, y;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long p;
		cin >> p;
		x[i + p]++;
		y[i - p]++;
	}

	for (auto it : x) ans += it.second * y[it.first];
	cout << ans;
}
