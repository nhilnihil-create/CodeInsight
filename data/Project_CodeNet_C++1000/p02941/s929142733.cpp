#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
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

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int64_t min_val = INT64_MAX;

#if 0
int64_t solve(const vector<int64_t> & as, vector<int64_t> & bs, int n, int64_t c);

int64_t decrease(const vector<int64_t> & as, vector<int64_t> & bs, int n, int64_t c, int i, int64_t d)
{
	int64_t nc = bs[i] / d;
	bs[i] -= (nc * d);
	int64_t ans = solve(as, bs, n, c + nc);
	bs[i] += (nc * d);
	return ans;
}

int64_t solve(const vector<int64_t> & as, vector<int64_t> & bs, int n, int64_t c)
{
	if (c >= min_val) return INT64_MAX;

	bool has_diff = false;
	FOR_LT(i, 0, n) {
		if (as[i] != bs[i]) {
			has_diff = true;
			break;
		}
	}
	if (!has_diff) {
		min_val = c;
		return c;
	}

	int64_t ans = INT64_MAX;

	if (bs[n - 1] + bs[1] < bs[0]) {
		int64_t d = bs[n - 1] + bs[1];
		ans = min(ans, decrease(as, bs, n, c, 0, d));
	}
	FOR_LE(i, 1, n - 2) {
		if (bs[i - 1] + bs[i + 1] < bs[i]) {
			int64_t d = bs[i - 1] + bs[i + 1];
			ans = min(ans, decrease(as, bs, n, c, i, d));
		}
	}
	if (bs[n - 2] + bs[0] < bs[n - 1]) {
		int64_t d = bs[n - 2] + bs[0];
		ans = min(ans, decrease(as, bs, n, c, n - 1, d));
	}

	return ans;
}
#endif

struct Search {
	int i;
	int64_t v;
};


auto comp = [](const Search & lhs, const Search & rhs) {
	return lhs.v < rhs.v;
};

void update(const vector<int64_t>& as, const vector<int64_t> & bs, int n, int i, priority_queue<Search, vector<Search>, decltype(comp)>& move_idx)
{
	if (i < 0) i += n;
	if (n <= i) i -= n;

	if (as[i] == bs[i]) return;

	if (i == 0) {
		if (bs[n - 1] + bs[1] < bs[0]) move_idx.push({ 0, bs[0] - bs[1] - bs[n - 1] });
	}
	else if (i == n - 1) {
		if (bs[n - 2] + bs[0] < bs[n - 1]) move_idx.push({ n - 1, bs[n - 1] - bs[0] - bs[n - 2]} );
	}
	else {
		if (bs[i - 1] + bs[i + 1] < bs[i]) move_idx.push({ i, bs[i] - bs[i + 1] - bs[i - 1] });
	}
}


bool fullfilled(const vector<int64_t>& as, const vector<int64_t>& bs, int n)
{
	return (memcmp(&as[0], &bs[0], n * sizeof(int64_t))== 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int64_t> as(n);
	for (auto& a : as) {
		cin >> a;
	}

	vector<int64_t> bs(n);
	for (auto& b : bs) {
		cin >> b;
	}

	int ce = 0;
	FOR_LT(i, 0, n) {
		if (as[i] == bs[i]) ce++;
		if (bs[i] < as[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	priority_queue<Search, vector<Search>, decltype(comp)> move_idx(comp);

	FOR_LT(i, 0, n) {
		update(as, bs, n, i + 1, move_idx);
	}

	int64_t ans = 0;

	while (ce != n) {
		if (move_idx.empty()) {
			cout << -1 << endl;                            
			return 0;
		}
		Search s = move_idx.top();
		int i = s.i;
		move_idx.pop();

		int64_t d = 0;
		if (i == 0) {
			d = bs[n - 1] + bs[1];
		}
		else if (i == n - 1) {
			d = bs[n - 2] + bs[0];
		}
		else {
			d = bs[i - 1] + bs[i + 1];
		}

		if (d <= as[i]) {
			if ((bs[i] - as[i]) % d != 0) {
				cout << -1 << endl;
				return 0;
			}
			ans += (bs[i] - as[i]) / d;
			bs[i] = as[i];
		}
		else {
			int64_t c = bs[i] % d;
			if (c < as[i]) {
				cout << -1 << endl;
				return 0;
			}
			ans += bs[i] / d;
			bs[i] = c;
		}

		if (bs[i] == as[i]) {
			ce++;
		}

		update(as, bs, n, i + 1, move_idx);
		update(as, bs, n, i - 1, move_idx);
	}

	cout << ans << endl;

	return 0;
}