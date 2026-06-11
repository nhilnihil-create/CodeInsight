#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	int ans = 0;
	rep(i, 1, n + 1) {
		string s = to_string(i);
		ans += (int)s.size() % 2;
	}
	cout << ans;
	return 0;
}