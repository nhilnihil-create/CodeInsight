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
#include <numeric>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define co(i) cout << i << endl;
#define co2(i,j) cout << i << " " << j << endl;
#define co3(i) cout << i << " ";
#define po(i) cout << i.first << " " << i.second << endl;
void in() {}
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
//rep, vin, all, iteLoop, bitSearch, bitList, nod, digitDP, treeDP//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vpll flag, D; vll path;
//***********//
int main() {
	cin >> N;
	string S;
	cin >> S;
	vl A(2*N);
	A[i] = 0;
	if (S[0] == 'W' || S[2*N - 1] == 'W') {
		cout << 0;
		exit(0);
	}
	for (i = 0; i < 2*N-1; i++) {
		if (S[i] == S[i + 1]) {
			A[i + 1] = (A[i] + 1) % 2;
		}
		else {
			A[i + 1] = A[i];
		}
	}
	vl R(2*N + 1), L(2*N + 1);
	R[0] = 0; L[0] = 0;
	for (i = 0; i < 2*N; i++) {
		R[i + 1] = R[i]; L[i + 1] = L[i];
		if (A[i] == 0) L[i + 1]++;
		else R[i + 1]++;
	}
	if (R[2*N] != L[2*N]) {
		cout << 0;
		exit(0);
	}
	ans = 1;
	for (i = 0; i < 2*N; i++) {
		if (A[i] == 1) {
			(ans *= (L[i] - R[i])) %= MOD;
		}
	}
	for (i = 1; i <= N; i++) {
		(ans *= i) %= MOD;
	}
	co(ans);
}
