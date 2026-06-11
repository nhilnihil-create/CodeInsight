#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long A, B, C;
	cin >> A >> B >> C;

	if (C - A - B < 0LL) {
		cout << "No" << endl;
		return 0;
	}

	long long S1 = 4LL * A * B;
	long long S2 = (C - A - B) * (C - A - B);
	if (S1 < S2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}