#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int n, t;
V<P> food;
int memo[3030][3030];

int dp(int i, int j) {
	if (i < 0 || j < 0)return -INF;
	if (memo[i][j])return memo[i][j];
	if (i == 0 || j == 0)return 0;
	int res;
	res = max(dp(i - 1, j), dp(i - 1, j - food[i - 1].first) + food[i - 1].second);
	memo[i][j] = res;
	return res;
}

int main() {
	
	cin >> n >> t;
	food.resize(n);
	rep(i, n)cin >> food[i].first >> food[i].second;
	sort(all(food));
	int ans = 0;
	rep(i, n)ans = max(ans, dp(i, t - 1) + food[i].second);
	cout << ans << endl;

}