#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7


#define GIRI 0
#define LESS 1

ll dp[100005][2];

int main(){
	string L;
	cin >> L;


	dp[0][GIRI] = 1;

	rep(i, L.size()) {
		ll num = L[i] - '0';
		if(num == 1) {
			dp[i+1][GIRI] += 2 * dp[i][GIRI];
			dp[i+1][GIRI] %= DIV;

			dp[i+1][LESS] += dp[i][GIRI];
			dp[i+1][LESS] %= DIV;

			dp[i+1][LESS] += 3 * dp[i][LESS];
			dp[i+1][LESS] %= DIV;

		} else {
			dp[i+1][GIRI] += dp[i][GIRI];
			dp[i+1][GIRI] %= DIV;

			dp[i+1][LESS] += 3 * dp[i][LESS];
			dp[i+1][LESS] %= DIV;
		}
	}
	cout << (dp[L.size()][0] + dp[L.size()][1])%DIV << endl;


}
