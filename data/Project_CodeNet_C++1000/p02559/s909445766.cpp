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
	fenwick_tree<long long> fw(n);
	for (int i = 0; i < n; ++i) {
		long long tmp;
		cin >> tmp;
		fw.add(i, tmp);
	}
	vector<long long> t(q), u(q), v(q);
	for (int i = 0; i < q; ++i) {
		cin >> t.at(i) >> u.at(i) >> v.at(i);
	}
	for (int i = 0; i < q; ++i) {
		if (t.at(i) == 0) {
			fw.add(u.at(i), v.at(i));
		} else {
			cout << fw.sum(u.at(i), v.at(i)) << endl;
		}
	}
}