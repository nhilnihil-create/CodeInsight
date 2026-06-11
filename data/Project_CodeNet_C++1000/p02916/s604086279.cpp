#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], b[n], c[n-1];
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i<n; i++) cin >> b[i];
	for (int i = 0; i<n-1; i++) cin >> c[i];
	
	int ret = b[a[0]];
	for (int i = 1; i<n; i++) {
		ret += b[a[i]];
		if (a[i] - a[i-1] == 1) ret += c[a[i-1]];
	}
	cout << ret << '\n';
}

