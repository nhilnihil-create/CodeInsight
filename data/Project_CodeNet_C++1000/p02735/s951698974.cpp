#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007
# define vi vector<ll>
# define vvi vector<vi>
# define rep(i, N) for (int i = 0; i < N; i++)
# define Rep(i, N) for (int i = 1; i <= N; i++)
# define deb(x) cerr << #x << ": " << x << endl;
# define deb2(x, i) cerr << #x << "[" << i << "]: " << x[i] << endl;
/*
vi v(10, 2); 
rep(i, 10) deb2(v, i); 
*/

/*
int a; cin >> a;
int a, b; cin >> a >> b;
rep(i, n){cin >> v[i];}
cout <<   << endl;
*/
int dp[101][101];
char m[101][101];

signed		main()
{
	int h, w; cin >> h >> w;
	rep(i, h)
	{
		cin >> m[i];
	}
	dp[0][0] = (m[0][0] == '#');
	rep(i, h)rep(j, w)
	{
		if (i + j == 0) continue;
		dp[i][j] = 1000000;
		if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (m[i][j] == '#' && m[i - 1][j] == '.'));
		if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (m[i][j] == '#' && m[i][j - 1] == '.'));
	}
	cout << dp[h - 1][w - 1] << endl;
}

