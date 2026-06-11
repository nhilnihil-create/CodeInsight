#include <bits/stdc++.h>

using namespace std;

int n, ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		ans += (n - 1) / i;
	return cout << ans << endl, 0;
}