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
	long long N, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i % 3 != 0 && i % 5 != 0) sum += 1LL * i;
	}
	cout << sum << endl;
	return 0;
}