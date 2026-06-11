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
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	while (true) {
		C -= B;
		if (C <= 0) {
			cout << "Yes" << endl;
			return 0;
		}
		A -= D;
		if (A <= 0) {
			cout << "No" << endl;
			return 0;
		}
	}

	return 0;
}
