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
	int p = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		p += v[i];
	}
	p /= n;
	int res1 = 0;
	for (int i = 0; i < n; i++) {
		res1 += (p - v[i]) * (p - v[i]);
	}
	p++;
	int res2 = 0;
	for (int i = 0; i < n; i++) {
		res2 += (p - v[i]) * (p - v[i]);
	}
	cout << min(res1, res2) << endl;
}
