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
//gcdlcm, isPrime, eratos, Npow, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vll path;
//***********//
vl divisor(ll n) {
	vl ret;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i != 1 && i * i != n) ret.push_back(n / i);
		}
	}
	ret.push_back(n);
	return ret;
}

int main() {
	cin >> N >> K;
	vl A(N);
	ll sum = 0;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	vl D = divisor(sum);
	sort(D.begin(), D.end());
	reverse(D.begin(), D.end());
	for (i = 0; i < D.size(); i++) {
		vl M;
		ll can = 1;
		for (j = 0; j < N; j++) {
			if (A[j] % D[i] != 0) {
				M.push_back(A[j] % D[i]);
			}
		}
		sort(M.begin(), M.end());
		ll L = M.size();
		if (L != 0) {
			vl P(L + 1), Q(L + 1);
			P[0] = 0; Q[0] = 0;
			for (j = 0; j < L; j++) {
				P[j + 1] = P[j] + M[j];
				Q[j + 1] = Q[j] + (D[i] - M[j]);
			}
			ll pre = INF;
			for (j = 0; j < L; j++) {
				if (P[j] == Q[L] - Q[j]) pre = min(pre, P[j]);
			}
			//debug(pre);
			if (pre > K) can = 0;
		}
		if (can) {
			cout << D[i];
			exit(0);
		}
	}
}
