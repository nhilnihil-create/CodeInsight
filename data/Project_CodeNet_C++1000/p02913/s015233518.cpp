#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int n;
string s;
int mem[5050][5050];

int dp(int i, int j) {
	if (i == n || j == n || i >= j)return 0;
	if (mem[i][j])return mem[i][j] - 1;

	int ret = 0;
	if (s[i] == s[j])ret = dp(i + 1, j + 1) + 1;
	ret = min(ret, j - i);
	mem[i][j] = ret + 1;
	return ret;
}

int main() {
	
	cin >> n >> s;
	int ans = 0;
	rep(i, n + 1)rep(j, n + 1)ans = max(ans, dp(i, j));
	cout << ans << endl;

}