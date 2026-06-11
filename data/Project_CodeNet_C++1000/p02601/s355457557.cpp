#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int op = 0;
	while (b <= a) {
		b *= 2;
		op++;
	}
	while (c <= b) {
		c *= 2;
		op++;
	}
	cout << (op <= k ? "Yes" : "No");
}

