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

int64_t solve(vector<int64_t> & as, int i, int n, int k, int64_t v, int64_t a)
{
	if (i == n) {
		return a;
	}

	if (i != -1) {
		a = a + max((int64_t)0, as[i] - v);
	}

	int64_t pv = v;
	v = 0;
	if (i != -1) {
		v = as[i];
	}

	static map<pair<int, int>, int64_t> memo;
	auto it = memo.find({ i, k });
	if (it != memo.end()) {
		return it->second + a;
	}

	int64_t ans = INT64_MAX;
	FOR_LE(j, i + 1, n) {
		if (k < j - i - 1) {
			break;
		}

		ans = min(ans, solve(as, j, n, k - (j - i - 1), v, a));
	}

	memo.insert({ { i, k}, ans - a });

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n, k; cin >> n >> k;
	vector<int64_t> as(n); for (auto& a : as) { cin >> a; }

	int64_t ans = solve(as, -1, n, k, 0, 0);
	cout << ans << endl;

	return 0;
}