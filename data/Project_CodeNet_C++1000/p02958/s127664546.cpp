#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	rep(i, 0, n) {
		rep(j, i, n) {
			swap(a[i], a[j]);

			bool ok = true;
			rep(k, 0, n - 1) {
				if (a[k] > a[k + 1]) ok = false;
			}
			if (ok) {
				cout << "YES";
				return 0;
			}
			swap(a[i], a[j]);
		}
	}
	cout << "NO";
	return 0;

}
