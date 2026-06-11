#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int n;
	while ( cin >> n, n ) {
		ll dp[50] = {1};
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				dp[i+j] += dp[i];
			}
		}

		ll day = (dp[n] + 9) / 10;
		ll year = (day + 364) / 365;
		cout << year << endl;
	}
	
}