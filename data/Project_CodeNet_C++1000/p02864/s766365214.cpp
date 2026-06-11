#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll h[305], n, k;
ll dp[305][305][305];

ll solve(int pos, int last, int left){
    if(left < 0) return 1e18;
    if(pos > n) return 0;
    if(dp[pos][last][left] != -1) return dp[pos][last][left];
    ll r1 = solve(pos+1, last, left-1);
    ll r2 = solve(pos+1, pos, left) + max(0LL, h[pos]-h[last]);
    return dp[pos][last][left] = min(r1,r2);
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    cout << solve(1, 0, k) << endl;

	return 0;
}