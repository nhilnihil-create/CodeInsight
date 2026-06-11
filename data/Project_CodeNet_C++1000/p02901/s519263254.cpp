#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N, M;
	cin >> N >> M;
	vector<int>a(M), b(M);
	vector<vector<int>>c(M);
	rep(i, M) {
		cin >> a[i] >> b[i];
		c[i].resize(b[i]);
		rep(j, b[i])cin >> c[i][j];
		rep(j, b[i])c[i][j]--;
	}
	vector<int>dp(1ll << N, INF);
	dp[0] = 0;
	for (int i = 0; i < (1ll << N); i++) { //集合
		for (int j = 0; j < N; j++) { //次とるもの
			if ((i >> j) & 1)continue; //もうすでに含まれていたら
			for (int k = 0; k < M; k++) { //何番目の鍵を使う？
				bool isOK = false;
				for (int l = 0; l < b[k]; l++) {
					if (c[k][l] == j)isOK = true;
				}
				int ni = i;
				int nc = dp[i] + a[k];
				if (isOK) {
					for (int l = 0; l < b[k]; l++) {
						if ((ni >> c[k][l]) & 1)continue;
						ni |= 1ll << c[k][l];
						chmin(dp[ni], nc);
					}
				}
			}
		}
	}
	int ans = dp[(1ll << N) - 1];
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
}