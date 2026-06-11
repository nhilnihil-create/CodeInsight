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

long long X, S = 100;

int main() {
	cin >> X;
	for (int i = 1; i <= 100000; i++) {
		S += 1LL * S / 100LL;
		if (S >= X) { cout << i << endl; break; }
	}
	return 0;
}