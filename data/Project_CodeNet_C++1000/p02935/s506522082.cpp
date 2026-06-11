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
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	double res = v[0];
	for (int i = 1; i < n; i++) {
		res = (res + v[i]) / 2;
	}
	cout << setprecision(10) << res << endl;
}
