// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int x = 0;

	for(int i = 0; i < n - 2; i += 2) {
		x ^= v[i];
		x ^= v[i + 1];
	}

	vector<int> a(n);

	a[n - 1] = x ^ v[n - 2];

	for(int i = 0; i < n - 1; i++) {
		a[i] = a[n - 1] ^ v[n - 1] ^ v[i];
	}

	for(int i = 0; i < n; i++) cout << a[i] << " ";

	
	return 0;
}
