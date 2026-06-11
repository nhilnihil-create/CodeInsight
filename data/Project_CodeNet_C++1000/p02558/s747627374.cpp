#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <omp.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> t(q), u(q), v(q);
	for (int i = 0; i < q; ++i) {
		cin >> t.at(i) >> u.at(i) >> v.at(i);
	}
	dsu d(n);
	for (int i = 0; i < q; ++i) {
		if (t.at(i) == 0) {
			d.merge(u.at(i), v.at(i));
		} else {
			if (d.same(u.at(i), v.at(i))) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
}