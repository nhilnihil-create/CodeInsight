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
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>



using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A& a, const B& b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A& a, const B& b) { a = max(a, (A)b); };




int main() {
	ll N, K; cin >> N >> K;
	vector<ll> H(1 + N); REP(i, 1, 1 + N) cin >> H[i];
	vector<vector<unordered_map<ll,ll>>> dp(1 + N);
	REP(i, 0, N + 1) dp[i].resize(1 + K);
	dp[0][0][0] = 0;
	REP(i, 0, N) {
		REP(j, 0, 1 + K) {
			for (const auto& p : dp[i][j]) {
				if (dp[i + 1][j].count(H[i + 1]) == 0) dp[i + 1][j][H[i + 1]] = dp[i][j][p.first] + max(0LL, H[i + 1] - p.first);
				else mins(dp[i + 1][j][H[i + 1]], dp[i][j][p.first] + max(0LL, H[i + 1] - p.first));
				if (j < K) {
					if (dp[i + 1][j + 1].count(p.first) == 0) dp[i + 1][j + 1][p.first] = dp[i][j][p.first];
					else mins(dp[i + 1][j + 1][p.first], dp[i][j][p.first]);
				}
			}
		}
	}
	ll ans = 1e18;
	REP(i, 0, 1 + K) for (const auto& p : dp[N][i]) mins(ans, p.second);
	PRI(ans);
	return 0;
}
