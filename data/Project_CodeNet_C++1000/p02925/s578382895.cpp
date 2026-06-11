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
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D, enter; vll path;
void bfs(ll now) {
	queue<ll> Q;
	Q.push(now);
	D[now] = 0;
	flag[now] = 1;
	ll u;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (ll v = 0; v < path[u].size(); v++) {
			ll next = path[u][v];
			if (enter[next]==1) {
				D[next] = D[u] + 1;
				flag[next] = 1;
				Q.push(next);
				enter[next]--;
			}
			else {
				enter[next]--;
			}
		}
	}
}
int main() {
	cin >> N;
	ll M = N * (N - 1);
	flag.resize(M);
	D.resize(M);
	path.resize(M);
	enter.resize(M);
	//aとb(a<b)の試合をa*(n-1)+bと定義
	for (i = 0; i < N; i++) {
		//根は便宜上0
		ll preA = 0, preB = 0;
		for (j = 0; j < N-1; j++) {
			ll a = i;
			ll b;
			cin >> b; b--;
			if (a > b) swap(a, b);
			path[preA * (N - 1) + preB].push_back(a * (N - 1) + b);
			enter[a * (N - 1) + b]++;
			preA = a; preB = b;
		}
	}
	bfs(0);
	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			ll key = i * (N - 1) + j;
			if (!flag[key]) {
				cout << -1;
				exit(0);
			}
			else {
				ans = max(ans, D[key]);
			}
		}
	}
	cout << ans;
}