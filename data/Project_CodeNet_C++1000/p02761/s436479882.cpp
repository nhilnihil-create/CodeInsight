#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 0x3b9aca07;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> ans(n, -1);
	bool ok = true;
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		--a;
		if (ans[a] != -1 && ans[a] != b) ok = false;
		ans[a] = b;
	}
	if (ans[0] == 0 && n != 1) ok = false;
	if (!ok) cout << -1;
	else rep(i, 0, n) {
		if (ans[i] == -1) {
			if (i == 0 && n != 1) cout << 1;
			else cout << 0;
		}
		else cout << ans[i];
	}
	cout << endl;
	return 0;
}
