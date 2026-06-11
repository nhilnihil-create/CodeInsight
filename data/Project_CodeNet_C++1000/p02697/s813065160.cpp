#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a = 1, b = n;
	while(a < b && m) {
		cout << a << " " << b << "\n";
		++a; --b; --m;
		if((n & 1 ^ 1) && n - b + a >= b - a && n - 2 * b + 2 * a <= 2) --b;
	}
	cout << flush;
	return 0;
}
