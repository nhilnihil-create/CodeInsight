#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
int main(){
	int n,s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
	dp[0][0] = 1;

	//(T,U)のそれぞれに含めるか含めないかを全通り数え上げれば,答えを求めたことになる.
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= s;j++){
			dp[i+1][j] += 2 * dp[i][j];//取らない場合は(T,U)について2通りに分岐する.
			dp[i+1][j] %= MOD;
			if(j + a[i] <= s){
				dp[i+1][j+a[i]] += dp[i][j];
				dp[i+1][j+a[i]] %= MOD;
			}
		}
	}

	cout << dp[n][s] << endl;
}
