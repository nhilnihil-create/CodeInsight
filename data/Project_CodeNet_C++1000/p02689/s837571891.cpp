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
	vector<int> v(n + 1, 1);
	vector<int> h(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> h[i + 1];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (h[a] <= h[b]) v[a] = 0;
		if (h[b] <= h[a]) v[b] = 0;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += v[i];
	}
	cout << res << endl;
}
