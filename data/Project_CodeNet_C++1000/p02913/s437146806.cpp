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

vector<int> zAlgorithm(const string & s) {
    int i = 1, j = 0, n = (int)s.size();
    vector<int> ret(n);
    ret[0] = n;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) ++j;
        ret[i] = j; // ここでi番目先頭の場合の値は確定
        if (j == 0) { // jが進んでなかったら
            ++i; continue;
        }
        int k = 1;
        while (i + k < n && k + ret[k] < j) ret[i + k] = ret[k], ++k;
        i += k, j -= k;
    }
    return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; string s; cin >> n >> s;

    int ans = 0;
    rep(i, 0, n) {
        vector<int> z = zAlgorithm(s.substr(i, n - i));
        rep(j, 0, z.size()) {
            if (z[j] <= j) ans = max(ans, z[j]);
        }
    }
    cout << ans << endl;
	return 0;
}
