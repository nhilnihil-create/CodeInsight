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
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
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
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv,  digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal ,RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag; vll path; vl D;
//***********//
vl divisor(ll n) {
	vl ret;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i != 1 && i * i != n) ret.push_back(n / i);
		}
	}
	ret.push_back(n);
	return ret;
}

int main() {
	cin >> N;
	ans = 0; // N=K
	if (N == 2) {
		cout << 1;
		exit(0);
	}
	vl P(1000001);
	for (k = 2; k <= 1000000; k++) {
		ll n = N;
		while (n % k == 0) n /= k;
		if (n == 1) {
			ans++; P[k] = 1;
		}
		else {
			if ((n - 1) % k == 0) {
				ans++;
				P[k] = 1;
			}
		}
	}
	if (N > 1000000) ans++;
	vl D = divisor(N - 1); //debug(D);
	for (i = 0; i < D.size(); i++) {
		if (D[i] > 1000000) ans++;
		else if (!P[D[i]]) ans++;
	}
	cout << ans;
}
