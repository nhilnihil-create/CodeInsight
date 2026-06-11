#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, v, b, w; cin >> a >> v >> b >> w;
	int t; cin >> t;
	if (((long long)v - w) * t >= abs(a - b)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
