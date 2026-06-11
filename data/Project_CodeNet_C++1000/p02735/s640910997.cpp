// #pragma comment(linker,"/STACK:1024000000,1024000000")
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define reT() int T; cin >> T; rep(t, 0, T)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define pw(x) (1ll<<(x))
#define modadd(a,b) {a+=b;a%=MOD;}
#define modmul(a,b) {a*=b;a%=MOD;}
#define LL long long
#define IN freopen("in", "r", stdin)
#define OUT freopen("out", "w", stdout)
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
const int inf = 0x3f3f3f3f;
const int N = 110;

int n, m;
char a[N][N];
int dp[N][N];
int main() {
	//IN;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n >> m) {
		rep(i, 1, n + 1) rep(j, 1, m + 1) {
			cin >> a[i][j];

			if (i == 1 && j == 1) {
				dp[i][j] = (a[i][j] == '#');
				continue;
			}

			dp[i][j] = inf;
			if (i - 1 >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i][j] == '#' && a[i - 1][j] == '.'));
			if (j - 1 >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (a[i][j] == '#' && a[i][j - 1] == '.'));
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
