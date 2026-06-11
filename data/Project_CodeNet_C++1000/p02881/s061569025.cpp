#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
using ll = long long;

int main() {
	long long N;
	cin >> N;

	long long ans = N;
	double sqrtNum = sqrt(N);
	for (int i = 1; i <= sqrtNum; ++i) {
		if (N % i == 0) {
			long long result = (N / i) - 1 + i - 1;
			if (ans > result) {
				ans = result;
			}
			else {
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
