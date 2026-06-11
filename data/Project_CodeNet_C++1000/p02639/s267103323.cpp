#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 15;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		ans -= n;
	}
	cout << ans << '\n';
	return 0;
}
