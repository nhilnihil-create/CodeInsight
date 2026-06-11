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
	priority_queue<int> pq;
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pq.push(t);
	}
	for (int i = 0; i < m; i++) {
		int t = pq.top();
		pq.pop();
		pq.push(t / 2);
	}
	while (pq.size() > 0) {
		int t = pq.top();
		res += t;
		pq.pop();
	}
	cout << res << endl;
}
