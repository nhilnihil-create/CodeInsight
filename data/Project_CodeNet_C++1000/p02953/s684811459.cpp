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
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			cout << "No" << endl;
			return 0;
		}
		if (v[i] > v[i - 1]) v[i]--;
	}
	cout << "Yes" << endl;
}
