#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

bool broken[100001];
ll dp[100001];

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		broken[x] = true;
	}

	dp[0] = 1;
	if (!broken[1]) dp[1] = 1;
	for (int i = 2; i <= n; i++){
		if (!broken[i]){ 
			dp[i] += dp[i-1];
			dp[i] += dp[i-2];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
