#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int dp[5001][5001];


int main(){
	int n;
	string s;
	cin >> n >> s;

	reverse(s.begin(), s.end());

	for (int i = 0; i < s.length(); i++){
		if (s[i] == s[0]){
			dp[i][0] = 1;
			dp[0][i] = 1;
		}else{
			dp[i][0] = 0;
			dp[0][i] = 0;
		}
	}

	for (int i = 1; i < s.length(); i++){
		for (int j = 1; j < s.length(); j++){
			if (s[i] == s[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = 0;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < s.length(); i++){
		for (int j = i+1; j < s.length(); j++){
			if (i + dp[i][j] > j) ans = max(ans, j-i);
			else ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
	return 0;
}
