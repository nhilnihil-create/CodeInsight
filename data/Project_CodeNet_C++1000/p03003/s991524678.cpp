#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define what_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << e << ' '; cerr << '\n'; //vector, set
#define what_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << x[i] << ' '; cerr <<  '\n'; //n first element of array
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define st first
#define nd second
#define cerr_pair(x) '{' << x.st << ", " << x.nd << '}'
#define pwhat_is(x) cerr << #x << " is " << cerr_pair(x) << endl;
#define pwhat_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << cerr_pair(e) << ' '; cerr << '\n'; //vector, set
#define pwhat_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << cerr_pair(x[i]) << ' '; cerr <<  '\n'; //n first element of array
#define endl '\n'
#define int long long

typedef pair<int,int> pii;
const int N = 2e3+5;
const int M = 2e3+5;
const int INF = 1e9;
const int MOD = 1e9+7;

int n, m, s[N], t[M];
int f[N][M];

int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> s[i];
	}
	for(int i=1; i<=m; i++) {
		cin >> t[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j] = f[i-1][j] + f[i][j-1] + MOD - f[i-1][j-1];
			if (s[i] == t[j]) f[i][j] += 1 + f[i-1][j-1];
			f[i][j] %= MOD;
		}
	}
	int ans = f[n][m] + 1;
	cout << ans << endl;
	return 0;
}
