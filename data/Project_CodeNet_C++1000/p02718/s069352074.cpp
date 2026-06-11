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
	vector<int> v(n, 0);
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		t += v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	if (v[m - 1] * 4 * m >= t) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
