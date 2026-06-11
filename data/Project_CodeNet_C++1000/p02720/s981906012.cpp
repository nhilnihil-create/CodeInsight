#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main()
{
	ll k;
	cin >> k;
	if(k < 10){
		cout << k << endl;
		return 0;
	}

	auto dp = vector<vector<ll>>(12, vector<ll>(10));
	for(int i = 0; i < 10; ++i){
		dp[1][i] = 1LL;
	}

	auto ans = [&dp, &k](auto ans, int d, int c)-> void {
		if(d == 0) return;
		for(int i = max(0, c - 1); i <= min(9, c + 1); ++i){
			if(k <= dp[d][i]){
				cout << i;
				ans(ans, d - 1, i);
				break;
			}else{
				k -= dp[d][i];
			}
		}
	};

	ll cnt = 9LL;
	for(int i = 2; i < 12; ++i){
		bool finish = false;
		dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
		for(int j = 1; j < 10; ++j){
			dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + (j < 9 ? dp[i - 1][j + 1] : 0);
			if(k <= cnt + dp[i][j]){
				k -= cnt;
				cout << j;
				ans(ans, i - 1, j);
				finish = true;
				break;
			}
			cnt += dp[i][j];
		}
		if(finish) break;
	}
	return 0;
}