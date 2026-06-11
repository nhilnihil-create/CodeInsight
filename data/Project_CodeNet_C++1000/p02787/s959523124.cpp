#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll damage[1005];
ll cost[1005];

ll memo[1005][10005];

ll dp(int i, int h){
	if (memo[i][h] != -1) return memo[i][h];

	ll ans = 1'000'000'000;

	if (damage[i] >= h) {ans = min(ans, cost[i]);}
	else { ans = min(ans, cost[i] + dp(i, h-damage[i]));}
	if (i < (n-1)) ans = min(ans, dp(i+1,h));

	memo[i][h] = ans;
	return ans;

}

int main(){
	memset(memo, -1, sizeof memo);
	int h;
	cin >> h >> n;
	for (int i = 0; i < n; i++){ cin >> damage[i] >> cost[i]; }
	cout << dp(0,h) << endl;
}

