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
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1, 0);
	for (int i = 0; i < k; i++) {
		int kk;
		cin >> kk;
		for (int j = 0; j < kk; j++) {
			int t;
			cin >> t;
			v[t]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) res++;
	}
	cout << res << endl;
}
