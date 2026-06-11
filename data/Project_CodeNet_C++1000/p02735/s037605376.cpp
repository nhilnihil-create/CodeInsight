#include <bits/stdc++.h>
#define pb push_back
#define pii pair<ll, ll>
#define nyan "(=^･ω･^=)"
#define read_input         freopen("in.txt","r", stdin)
#define print_output       freopen("out.txt","w", stdout)
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
int g[1005][1005];
int dp[1005][1005][2];

int answer(int i, int j, int now) {
	if(i > n || j > m) return 1e9+7;
	if(i == n && j == m) return 0;
	if(dp[i][j][now] != -1) return dp[i][j][now];

	int ans = 1e9+7;
	if(now == 0) {
		if(g[i+1][j] == 0) ans = min(ans, answer(i+1, j, now));
		else ans = min(ans, answer(i+1, j, now ^ 1) + 1);

		if(g[i][j+1] == 0) ans = min(ans, answer(i, j+1, now));
		else ans = min(ans, answer(i, j+1, now ^ 1) + 1);
	}

	else {
		if(g[i+1][j] == 1) ans = min(ans, answer(i+1, j, now));
		else ans = min(ans, answer(i+1, j, now ^ 1));

		if(g[i][j+1] == 1) ans = min(ans, answer(i, j+1, now));
		else ans = min(ans, answer(i, j+1, now ^ 1));
	}

	return dp[i][j][now] = ans;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		char ch; cin >> ch;
    		g[i][j] = (ch == '#');
    	} getchar();
    }

    memset(dp, -1, sizeof dp);

    int ans = 1e9+7;
    if(g[1][1] == 0) ans = answer(1, 1, 0);
    else ans = answer(1, 1, 1) + 1;

    cout << ans << endl;

    return 0;  
}