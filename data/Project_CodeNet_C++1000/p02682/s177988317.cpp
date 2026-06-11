#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
	int a, b, c, k;

	cin >> a >> b >> c >> k;

	int ans = 0;

	if (a >= k) {
		ans = k;
	}
	else if (a < k) {
		if (k - a <= b) {
			ans = a + 0 * b;
		}
		else if (k - a > b) {
			ans = a + 0 * b - (k - a - b);
		}
	}
	
	cout << ans << endl;

	return 0;
}