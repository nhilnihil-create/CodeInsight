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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> v(n + 1, vector<int>(0));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<long long int> increment(n + 1, 0);
	vector<long long int> res(n + 1, -1);
	for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		increment[p] += x;
	}
	vector<int> nodes(1, 1);
	res[1] = increment[1];
	while (nodes.size() > 0) {
		int node = nodes.back();
		nodes.pop_back();
		for (auto next : v[node]) {
			if (res[next] == -1) {
				nodes.push_back(next);
				res[next] = res[node] + increment[next];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
