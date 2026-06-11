#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll n, k;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n; 
	vector<int> a(n), b(n), c(n);
	rep(i, 0, n) cin >> a[i], --a[i];
	rep(i, 0, n) cin >> b[i];
	rep(i, 0, n - 1) cin >> c[i];

	int ans = 0;
	rep(i, 0, n) {
		int m = a[i];
		ans += b[m];
		if (i + 1 < n && a[i + 1] == m + 1) ans += c[m];
	}
	cout << ans << endl;
	return 0;
}