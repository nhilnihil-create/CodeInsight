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
vl flag, color, D; vll path;
int main() {
	ll P;
	cin >> N >> P;
	string S;
	cin >> S;
	vl U(N + 1);
	U[N] = 0;
	if (P == 2 || P == 5) {
		for (i = 0; i < N; i++) {
			if (ctoi(S[i]) % P == 0) {
				ans += i + 1;
			}
		}
		cout << ans;
	}
	else {
		map<ll, ll> M;
		//0文字選ぶとあまりは0
		M[0] = 1;
		ll sum = 0;
		ll keta = 1;
		for (i = N-1; i >= 0; i--) {
			(sum += ctoi(S[i]) * keta) %= P;
			(keta *= 10) %= P;
			M[sum]++;
		}
		for (auto x : M) {
			//MODが同じもの同士を選ぶ
			ans += x.second * (x.second - 1) / 2;
		}
		cout << ans;
	}
}