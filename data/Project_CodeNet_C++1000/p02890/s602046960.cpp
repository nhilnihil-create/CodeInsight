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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> vs(n + 1);
	FOR_LT(i, 0, n) {
		int v; cin >> v;
		vs[v]++;
	}

	sort(vs.begin(), vs.end(), greater<int>());

	vector<int> steps(n + 1);

	steps[vs[0]] = 1;
	FOR_LT(i, 1, n) {
		int v = vs[i];
		FOR_DW(j, vs[i - 1] - 1, v + 1) {
			steps[j] = i;
		}
		steps[v] = i + 1;
	}

	vector<int> ans(n + 1);
	FOR_DW(i, n - 1, 0) {
		if (vs[i + 1] != 0) {
			int v = vs[i + 1];
			int c = v;
			while (c != 0) {
				while (steps[v + 1] > i) v++;

				vs[steps[v + 1]]++;
				steps[v + 1]++;
				c--;
			}
		}

		ans[i] = vs[i];
	}

	FOR_LT(i, 0, n) {
		cout << ans[i] << endl;
	}

	return 0;
}