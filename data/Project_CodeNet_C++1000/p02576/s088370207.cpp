#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, t, res;
	cin >> n >> x >> t;

	res = (n / x + (n % x != 0)) * t;
	cout << res;
}