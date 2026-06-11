#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nn = (1 << n);
	map<int, int> m;
	for (int i = 0; i < nn; i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	vector<int> v;
	v.push_back(m.rbegin()->first);
	m[v.back()]--;
	if (m[v.back()] == 0) m.erase(v.back());
	while (m.size() > 0) {

		nn = v.size();
		for (int i = 0; i < nn; i++) {
			auto it = m.lower_bound(v[i]);
			if (it == m.begin()) {
				cout << "No" << endl;
				return 0;
			}
			it--;
			v.push_back(it->first);
			m[v.back()]--;
			if (m[v.back()] == 0) m.erase(v.back());
		}
	}
	cout << "Yes" << endl;
}
