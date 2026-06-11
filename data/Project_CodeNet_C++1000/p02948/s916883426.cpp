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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp(n, make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> vp[i].first >> vp[i].second;
	}
	sort(vp.begin(), vp.end());
	int index = 0;
	priority_queue<int> pq;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		while (index < vp.size() && vp[index].first <= i) {
			pq.push(vp[index].second);
			index++;
		}
		if (pq.size() > 0) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << endl;
}
