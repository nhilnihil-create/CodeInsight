#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

vector<int> sieve(int n) {
	vector<int> res;
	vector<bool> is_prime(n + 1, true);
	
	is_prime[0] = is_prime[1] = false;
	
	for (ll i = 2; i * i <= n; i++) if (is_prime[i]) {
		res.push_back(i);
		for (ll j = 1; i * j <= n; j++) is_prime[i * j] = false;
	}
	
	REP(i, n + 1) if (is_prime[i]) res.push_back(i);
	sort(res.begin(), res.end());
	return res;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	REP(i, N) scanf("%d", &A[i]);
	
	
	constexpr int MAXA = 1000000;

	auto prime = sieve(MAXA);
	
	vector<int> cnt(MAXA + 1);
	REP(i, N) ++cnt[A[i]];
	
	bool pairwise = true;
	for (int p : prime) {
		int cur = p;
		int sum = 0;
		while (cur <= MAXA) {
			sum += cnt[cur];
			cur += p;
		}
		if (sum > 1) pairwise = false;
	}
	
	int g = A[0];
	FOR(i, 1, N) g = gcd(g, A[i]);
	
	if (pairwise) puts("pairwise coprime");
	else if (g == 1) puts("setwise coprime");
	else puts("not coprime");
	
	return 0;
}
