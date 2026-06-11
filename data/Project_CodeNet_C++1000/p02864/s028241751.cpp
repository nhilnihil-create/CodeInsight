#include <bits/stdc++.h>
using namespace std;

/*
evenness - min humps
no reason to overlap
"already paying"
no reason to not match an adj column? -> no bridging
same as deleting k columns -> adding a row can only worse the situation, so we always want to delete
always want to delete -> which ones?
could do dp (range & left & right) -> N^4 states, O(1) trans
if you include 1 everything else lesser is free, however everything else you include you possibility
-> state of "current height, current position, #used" 
for each state either use or don't use the next one O(n^3) states, O(1) trans
*/
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;	
	cin >> n >> k;
	int a[n+1];
	a[0] = 0;
	for(int i = 1;i <= n; ++i)cin >> a[i];
	ll dp[n+1][n+1][k+1] = {};
	const ll inf = 1LL << 60;
	fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(dp[0][0][0]), inf);
	dp[0][0][0] = 0;
	for(int i = 0;i < n; ++i){
		for(int h = 0;h < n; ++h){
			for(int nk = 0; nk <= k; ++nk){
				// take	
				dp[i+1][i+1][nk] = min(dp[i+1][i+1][nk], dp[i][h][nk] + max(a[i+1] - a[h], 0));
				// dont
				if(nk != k){
					dp[i+1][h][nk+1] = min(dp[i+1][h][nk+1], dp[i][h][nk]);
				}
			}
		}
	}
	ll ans = *min_element(&dp[n][0][0], (&dp[n][n][k]) + 1);
	cout << ans << '\n';
}
