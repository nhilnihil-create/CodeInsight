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
	int res = 0;
	int c = 0;
	int last = -1;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (h > last) {
			last = h;
			c = 0;
		} else {
			last = h;
			c++;
			res = max(res, c);
		}
	}
	cout << res << endl;
}
