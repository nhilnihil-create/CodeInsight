#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int n, m, ans = 0;
	cin >> n >> m;

	if (n > 1) {
		ans += n*(n - 1) / 2;
	}
	if (m > 1) {
		ans += m*(m - 1) / 2;
	}

	cout << ans;
	return 0;
}