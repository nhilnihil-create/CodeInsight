#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int b[n-1];
	int a[n];
	for (int i = 0; i<n-1; i++) cin >> b[i];
	a[0] = b[0], a[1] = b[0];
	for (int i = 2; i<n; i++) {
		a[i] = b[i-1];
		if (b[i-1] < a[i-1]) a[i-1] = b[i-1];
	}
	int ret = 0;
	for (int i =0; i<n; i++) ret += a[i];
	cout << ret << '\n';
}

