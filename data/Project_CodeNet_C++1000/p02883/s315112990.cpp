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
ll binarySearch(vl V, ll key) {
	ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	ll right = V.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は V.size()
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (V[mid] >= key) right = mid;
		else left = mid;
	}
	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}
int main() {
	cin >> N >> K;
	vl A(N);
	vl F(N);
	for (i = 0; i < N; i++) cin >> A[i];
	for (i = 0; i < N; i++) cin >> F[i];
	sort(A.begin(), A.end());
	sort(F.begin(), F.end());
	reverse(F.begin(), F.end());
	ll left = -1;
	ll right = 0;
	for (i = 0; i < N; i++) {
		right += A[i] * F[i];
	}
	ll mid;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		ll key = 0;
		for (i = 0; i < N; i++) {
			//debug(i, A[i],F[i], mid);
			if (A[i] * F[i] > mid) key += (A[i] * F[i] - mid - 1) / F[i] + 1;
		}
		//debug(mid, key, K);
		if (key <= K) right = mid;
		else left = mid;
	}
	cout << right;
}