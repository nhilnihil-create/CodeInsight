#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, m, ans = 0;
	cin >> n >> m;
	ans += n * (n - 1);
	ans += m * (m - 1);
	ans /= 2;
	cout << ans << endl;
	return 0;
}
