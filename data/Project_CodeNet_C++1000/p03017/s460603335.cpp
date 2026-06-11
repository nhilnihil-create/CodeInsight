#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	string s; cin >> s;
	--a, --b, --c, --d;

	bool ok = true;
	rep(i, a, c) if (s[i] == '#' && s[i + 1] == '#') ok = false;
	rep(i, b, d) if (s[i] == '#' && s[i + 1] == '#') ok = false;

	if (c < d) {
		if (ok) cout << "Yes";
		else cout << "No";
	}
	else {
		bool three = false;
		rep(i, b, d + 1) {
			if (0 < i && i + 1 < n && s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') three = true;
		}
		if (three && ok) cout << "Yes";
		else cout << "No";
	}
	return 0;
}