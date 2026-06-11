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
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		um[v[i] + i]++;
	}
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		res += um[i - v[i]];
		if (i - v[i] == i + v[i]) res--;
	}
	cout << res << endl;
}
