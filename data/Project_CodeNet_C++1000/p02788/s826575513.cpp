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

struct M {
	int64_t x;
	int64_t v;
};

struct B {
	int64_t v;
	int64_t x;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int64_t n, d, a; cin >> n >> d >> a;
	vector<M> ms(n);
	FOR_LT(i, 0, n) {
		cin >> ms[i].x >> ms[i].v;
	}
	sort(ms.begin(), ms.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.x < rhs.x;
	});

	int64_t p = 0;
	int64_t sv = 0;
	int64_t ans = 0;

	list<B> rem;
	while (p < n) {
		int64_t nx = ms[p].x;
		if (ms[p].v - sv > 0) {
			int64_t nb = (ms[p].v - sv + a - 1) / a;
			ans += nb;

			sv += nb * a;
			int64_t ny = nx + d * 2;
			rem.push_back({ nb * a, ny });
		}

		p++;
		while (p != n && !rem.empty() && rem.front().x < ms[p].x) {
			sv -= rem.front().v;
			rem.pop_front();
		}
	}
	
	cout << ans << endl;

	return 0;
}