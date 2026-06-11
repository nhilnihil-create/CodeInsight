#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int main() {
	string S;
	cin >> S;
	int N = S.size();
	reverse(S.begin(), S.end());
	vector<int> pw(N);
	pw[0] = 1;
	for(int i = 1; i < N; ++i) {
		pw[i] = 3LL * pw[i - 1] % mod;
	}
	int ans = 0, cur = 1;
	for(int i = N - 1; i >= 0; --i) {
		if(S[i] == '1') {
			ans = (ans + 1LL * cur * pw[i]) % mod;
			cur = 2LL * cur % mod;
		}
	}
	ans = (ans + cur) % mod;
	cout << ans << endl;
	return 0;
}