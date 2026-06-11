
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
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

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
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };

int ctoi(char c) {
	return c - '0';
}
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
	string s;
	cin >> s;
	ll mod = 1e9 + 7;
	vector<vector<ll>> dp(s.size() + 1);
	for(auto & v : dp)v.resize(13, 0);
	if (s.back() == '?')REP(k, 0, 10)dp[1][k] = 1;
	else dp[1][ctoi(s.back())] = 1;
	REP(i, 2, s.size()+1) {
		char c = s[s.size() - i];
		REP(j, 0, 13) {
			if (c == '?') {
				REP(k, 0, 10) dp[i][j] += dp[i - 1][((j - k * modpow(10, i - 1, 13)) % 13 + 13) % 13];
			}
			else dp[i][j] += dp[i - 1][((j - ctoi(c) * modpow(10, i - 1, 13)) % 13 + 13) % 13];
			dp[i][j] %= mod;
		}
	}
	PRI(dp[s.size()][5]);
	return 0;
}