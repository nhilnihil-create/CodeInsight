#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 2000000000;
	cin >> n;
	int x[n];
	cina(x, n);
	for (int i = 1; i <= 100; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += (i-x[j])*(i-x[j]);
		}
		ans = min(ans, sum);
	}
	cout << ans;

	return 0;
}