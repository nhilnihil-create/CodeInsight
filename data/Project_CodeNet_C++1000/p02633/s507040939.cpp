#include <bits/stdc++.h>

using namespace std;

int main() {
	int x; cin >> x;
	long long g = 360ll / __gcd(1ll * x, 360ll);
	cout << g  << "\n";
	return 0;
}