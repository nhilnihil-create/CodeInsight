#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	int ans = min(n, 9);
	ans += min(max(n - 99, 0), 900);
	ans += min(max(n - 9999, 0), 90000);
	ans += min(max(n - 999999, 0), 9000000);

	cout << ans << endl;
}