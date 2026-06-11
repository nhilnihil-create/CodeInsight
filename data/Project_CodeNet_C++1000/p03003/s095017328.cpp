#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//bitSearch, bitList, gcdlcm, isPrime, primeFactorize, Npow, divisor, modinv, dfs, bfs, eratos//
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = INF; ll z = 0, o = 1;
vl flag, color, D; vll path;
int main() {
	cin >> N >> M;
	vl S(N), T(M);
	for (i = 0; i < N; i++) cin >> S[i];
	for (i = 0; i < M; i++) cin >> T[i];
	vll dp(N + 1, vl(M + 1));
	for (i = 0; i < N + 1; i++) dp[i][0] = 1;
	for (i = 0; i < M + 1; i++) dp[0][i] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			(dp[i+1][j+1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j]+MOD)%=MOD;
			if (S[i] == T[j]) (dp[i + 1][j + 1] += dp[i][j])%=MOD;
		}
	}
	cout << dp[N][M];
}