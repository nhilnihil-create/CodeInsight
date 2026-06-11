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

#include <atcoder/all>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n, q; cin >> n >> q;
	atcoder::fenwick_tree<int64_t> ft(n);
	FOR_LT(i, 0, n) {
		int a; cin >> a;
		ft.add(i, a);
	}

	REP(q) {
		int m; cin >> m;
		if (m == 0) {
			int p, x; cin >> p >> x;
			ft.add(p, x);
		}
		else {
			int a, b; cin >> a >> b;
			cout << ft.sum(a, b) << endl;
		}
	}

	return 0;
}