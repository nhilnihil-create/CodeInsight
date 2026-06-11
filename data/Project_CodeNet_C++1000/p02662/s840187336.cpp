
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define MINS(a,b) a = min(a,(decltype(a))(b))
#define MAXS(a,b) a = max(a,(decltype(a))(b))

ll modpow(ll r, ll n, ll mod) {
	ll ans = 1;
	ll tmp = r;
	while (n > 0) {
		if ((n & 1) > 0)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}
int main() {
	ll N, S;
	ll mod = 998244353;
	cin >> N >> S;
	vector<ll> A(1+N);
	vector<vector<ll>> dp(1 + N);
	REP(i, 1, 1 + N) {
		cin >> A[i];
		dp[i].resize(1 + S, 0);
	}
	if(A[1] <= S)dp[1][A[1]] = 1;
	REP(i, 2, N + 1) {
		REP(j, 1, S + 1) {
			dp[i][j] = dp[i - 1][j] * 2 % mod;
			if (j - A[i] > 0) {
				dp[i][j] += dp[i - 1][j - A[i]];
				dp[i][j] %= mod;
			}
		}
		if (A[i] <= S) {
			dp[i][A[i]] += modpow(2, i - 1, mod);
			dp[i][A[i]] %= mod;
		}
	}
	PRI(dp[N][S]);
	return 0;
}