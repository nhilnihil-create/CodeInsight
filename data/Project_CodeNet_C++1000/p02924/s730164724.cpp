#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {
	long long int N, ans;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			ans = 1;
		}
		else if (i != N) {
			ans += i;
		}
	}

	if (N == 1) {
		ans = 0;
	}

	cout << ans;

	return 0;
}
