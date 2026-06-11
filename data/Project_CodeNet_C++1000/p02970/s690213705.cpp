#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
	int n, d; cin >> n >> d;
	if (n <= d * 2 + 1) { cout << 1 << endl; return 0; }
	int ans = 1; n = n - d - 1;
	ans += n / (d + d + 1);
	if (n % (d + d + 1) > d) ans++;
	cout << ans << endl;
}
