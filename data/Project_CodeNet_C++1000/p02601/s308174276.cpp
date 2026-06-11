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
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	while (a >= b) {
		b *= 2;
		k--;
	}
	while (b >= c) {
		c *= 2;
		k--;
	}
	if (k < 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}	
}
