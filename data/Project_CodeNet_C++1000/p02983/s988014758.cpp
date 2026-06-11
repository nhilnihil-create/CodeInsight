#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long L, R; cin >> L >> R;
	long long ans = 2020;
	for (long long i = L; i < R; i++) {
		for (long long j = i + 1; j <= R; j++) {
			if (j % 2019 == 0 || i % 2019 == 0) {
				cout << 0 << endl;
				return 0;
			}
			else {
				long long num = (i % 2019) * (j % 2019) % 2019;
				ans = min(ans, num);
			}
		}
	}
	cout << ans << endl;
}
