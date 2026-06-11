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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int64_t n; cin >> n;

	vector<vector<int>> map(n + 1);
	vector<vector<int>> map2(n + 1);

	FOR_LT(i, 0, n - 1) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		map[a].push_back(b);
		map2[b].push_back(a);
	}

	int64_t ans = 0;
	vector<int64_t> pro(n + 1);
	int64_t t = 0;
	FOR_LE(i, 1, n) {
		//cout << t << " " << i << " " << pro[i] << endl;
		t += i;
		t -= pro[i];
		ans += t;
		//cout << ans << " " << t << endl;
		for (auto b : map[i]) {
			pro[b] += i;
		}
	}
	cout << ans << endl;

	return 0;
}
