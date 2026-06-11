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
	vector<int> v(n - 1, 0);
	for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	int res = v[0] + v.back();
	for (int i = 0; i + 1 < v.size(); i++) {
		res += min(v[i], v[i + 1]);
	}
	cout << res << endl;
}
