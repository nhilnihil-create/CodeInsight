#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <numeric>
#include <string>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;

	float  ans = n / 1.08;

	float  integral_part = 0;
	float fractional_part = std::modf(ans, &integral_part);

	if (fractional_part == 0.0) {
		cout << ans;
	}
	else {
		integral_part++;
		if ((int)(integral_part*1.08) == n) {
			cout << integral_part;
		}
		else {
			cout << ":(";
		}
	}
	return 0;
}
