#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 S;
	cin >> S;

	u64 mod = pow(10, 9) + 7;

	vector<u64> dp(4);
	dp[0] = 1;
	u64 sum_dp = 0;

	for(s64 i=3; i<=S; i++) {
		s64 i3 = (i - 3) %  4;
		sum_dp = (dp[i3] + sum_dp) % mod;
		dp[i%4] = sum_dp % mod;
	}
	
	cout << dp[S%4] << endl;
    return 0;
}
