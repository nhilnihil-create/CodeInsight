#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 10000000000
#define PI 3.141592653589793

int main() {
	long long a, b, c, k, ans = 0;
	cin >> a >> b >> c >> k;

	if (k > a + b) {
		ans += a;
		ans -= k - (a + b);
	} else if (k > a) {
		ans += a;
	} else {
		ans += k;
	}

	cout << ans;
	return 0;
}