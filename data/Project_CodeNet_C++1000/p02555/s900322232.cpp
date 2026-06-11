#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;





int main() {
	int s;
	cin >> s;
	if (s < 3) {
		cout << 0 << endl;
		return 0;
	}

	vector<ll> dp(s + 1,1);
	dp[0] = dp[1] = dp[2] = 0;
	for (int i = 3; i <= s; i++) {
		for (int j = 3; j <= i-3; j++) {
			dp[i] += dp[j];
			dp[i] %= MOD;
		}
	}
	cout << dp[s] << endl;
}