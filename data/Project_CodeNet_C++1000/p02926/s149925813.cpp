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
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

#define PI  3.14159

using namespace std;

struct E {
	int x;
	int y;
	double theta;
};

bool in_range(double from, double to)
{
	if (from > 0 && to < 0) to += 2 * PI;
	return (to - from) < PI;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<E> es;
	FOR_LT(i, 0, n) {
		int x, y; cin >> x >> y;
		if (x != 0 || y != 0) es.push_back({ x, y, atan2(y, x) });
	}

	std::sort(es.begin(), es.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.theta < rhs.theta;
	});

	double ans = 0;
	FOR_LT(i, 0, es.size()) {
		int x = 0;
		int y = 0;

		int j = i;
		while (true) {
			if (hypot(x, y) >= hypot(x + es[j].x, y + es[j].y)) break;

			x += es[j].x;
			y += es[j].y;

			j++;
			if (es.size() <= j) j -= es.size();
			if (j == i) break;
		}

		ans = max(ans, hypot(x, y));
	}

	cout << std::setprecision(30) << ans << endl;

	return 0;
}