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

	int n;
	cin >> n;

	vector<int> vs(n + 1);
	FOR_LT(i, 0, n) {
		int v; cin >> v;
		vs[v]++;
	}

	vector<int> ds(n + 1);
	FOR_LE(i, 1, n) {
		ds[vs[i]]++;
	}

	vector<int> kdk(n + 1);
	vector<int> dk(n + 2);

	FOR_LE(k, 1, n) {
		kdk[k] = kdk[k - 1] + k * ds[k];
		dk[k] = dk[k - 1] + ds[k];
	}

	vector<int> fs(n + 2);
	FOR_LE(i, 1, n) {
		fs[i] = (kdk[i] + i*(dk[n] - dk[i])) / i;
	}

	int c = n;
	FOR_LE(v, 1, n) {
		while (c != 0 && fs[c] < v) c--;
		cout << c << endl;
	}

	return 0;
}