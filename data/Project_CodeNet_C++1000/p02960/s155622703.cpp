#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;


string S;
ll dp[100001][13];
ll keta[100001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	keta[0] = 1;
	FOR(i, 1, 100001) {
		keta[i] = (keta[i - 1] * 10) % 13;
	}

	cin >> S;
	ll N = S.length();
	if (S[N - 1] == '?') {
		FOR(i, 0, 10)dp[0][i] = 1;
	}
	else {
		dp[0][ll(S[N - 1] - '0')] = 1;
	}

	FOR(i, 1, N) {
		ll cur = N - 1-i;
		if (S[cur] == '?') {
			FOR(j, 0, 13) {
				FOR(k, 0, 10) {
					dp[i][(j + k*keta[i])%13] += dp[i - 1][j];
					dp[i][(j + k * keta[i]) % 13] %= mod;
				}
			}
		}
		else {
			ll num = ll(S[cur] - '0');
			FOR(j, 0, 13) {
				dp[i][(j + keta[i] * num) % 13] += dp[i - 1][j];
				dp[i][(j + keta[i] * num) % 13] %= mod;
			}
		}

	}

	cout << dp[N - 1][5] << endl;

}
