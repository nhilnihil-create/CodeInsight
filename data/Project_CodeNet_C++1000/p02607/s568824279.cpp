#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a;
		if ((i&1) && (a&1)) ans ++;
	}
	cout << ans << endl;
	return 0;
}
