#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	double N;
	cin >> N;

	double odd = 0;
	for (int i = 1; i <= N; ++i) {
		if (i % 2) {
			odd++;
		}
	}

	cout << odd / N << endl;
	return 0;
}
