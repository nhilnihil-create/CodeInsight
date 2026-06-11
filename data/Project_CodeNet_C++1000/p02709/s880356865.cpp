#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)


using namespace std;

int64_t dp[4010][4010];

struct V {
	int64_t a;
	int i;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int64_t n; cin >> n;
	vector<V> vs(n);
	FOR_LT(i, 0, n) {
		int a; cin >> a;
		vs[i] = { a,i };
	}
	sort(vs.begin(), vs.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.a > rhs.a;
	});

	FOR_LT(i, 0, n) {
		int x = i + 1;
		int y = 0;

		int pl = vs[i].i;
		int pr = n - 1 - vs[i].i;
		while (0 <= x) {
			int64_t v = 0;
			if (x != 0) {
				v = max(v, dp[x - 1][y] + vs[i].a * (pl - x + 1));
			}
			if (y != 0) {
				v = max(v, dp[x][y - 1] + vs[i].a * (pr - y + 1));
			}

			dp[x][y] = v;
			x--;
			y++;
		}

	}

	int64_t ans = 0;
	FOR_LE(x, 0, n) {
		int y = n - x;
		ans = max(ans, dp[x][y]);
	}
	cout << ans << endl;

	return 0;
}
