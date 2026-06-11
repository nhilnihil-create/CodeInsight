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
	int c = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		res += t * c;
		c += t;
	}
	cout << res << endl;
}
