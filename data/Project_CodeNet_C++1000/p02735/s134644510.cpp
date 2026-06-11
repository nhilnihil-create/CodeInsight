#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

int n, m, dp[105][105];
char board[105][105];

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++) cin >> board[i][j];
	}
	dp[1][1] = (board[1][1] == '#');
	for(int i = 2; i <= n; i++){
	    dp[i][1] = dp[i - 1][1];
	    if(board[i][1] == '#' && board[i - 1][1] == '.') dp[i][1]++;
	}
	for(int i = 2; i <= m; i++){
	    dp[1][i] = dp[1][i - 1];
	    if(board[1][i] == '#' && board[1][i - 1] == '.') dp[1][i]++;
	}
	for(int i = 2; i <= n; i++){
	    for(int j = 2; j <= m; j++){
	        if(board[i][j] == '.') dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
	        else{
	            int tmp1 = dp[i - 1][j] + (board[i - 1][j] == '.'), tmp2 = dp[i][j - 1] + (board[i][j - 1] == '.');
	            dp[i][j] = min(tmp1, tmp2);
	        }
	    }
	}
	cout << dp[n][m];
}

/*
TEST HERE
INPUT #1

OUTPUT #1


INPUT #2

OUTPUT #2


INPUT #3

OUTPUT #3

*/
