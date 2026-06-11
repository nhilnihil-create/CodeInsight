#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 30;
int n, m, x, y, q, d; ll z, w = 0, sum = 0; int ans = 0;
const int MAX = 510000;
const int MOD = 1000000007;
int main(void) {
	int dp[100100][13];
	string s; int d; cin >> s;
	Fill(dp, 0);
	dp[0][0] = 1;
	rep(i, s.size()) {
		if (isdigit(s[i])) {
			int Si = s[i] - '0';
			rep(j, 13) {
				dp[i + 1][(j*10 + Si) % 13] += dp[i][j];
				dp[i + 1][(j*10 + Si) % 13] %= MOD;
			}
		}
		else {
			rep(j, 13) {
				rep(k, 10) {
					dp[i + 1][(j*10 + k) % 13] += dp[i][j];
					dp[i + 1][(j*10 + k) % 13] %= MOD;
				}
			}
		}
	}cout << dp[s.size()][5] << endl;
}
