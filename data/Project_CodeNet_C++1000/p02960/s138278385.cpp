#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	string S;
	cin >> S;
	vector<int> dp(13);
	dp[0] = 1;
	for (char ch : S) {
		vector<int> ndp(13);
		for (int i = 0; i < 13; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (ch == '?' || ch == char(j + '0')) {
					ndp[(10 * i + j) % 13] += dp[i];
					if (ndp[(10 * i + j) % 13] >= mod) ndp[(10 * i + j) % 13] -= mod;
				}
			}
		}
		dp = ndp;
	}
	cout << dp[5] << endl;
	return 0;
}