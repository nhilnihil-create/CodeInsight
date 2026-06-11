#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	ll X;
	cin >> X;

	ll yokin = 100;
	int ans = 0;
	while (X > yokin) {
		yokin += yokin / 100;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
