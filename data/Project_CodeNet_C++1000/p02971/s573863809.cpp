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
	vector<int> v1 = v;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (v1[i] == v.back())
			cout << v[n - 2] << endl;
		else
			cout << v.back() << endl;
	}
}
