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
vll flag, D; vll path;
//***********//
/* BIT: RAQ対応BIT
    BITはインデックスが1から始まっているので要注意！！！！
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    ・query(l,r)：[l,r)の区間和を取得する
    ・value(i)：i番目の値を取得する
    ・lower_bound(i)：BIT内で通常の二分探索(※単調性を満たす場合のみ)
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    ll n; vector<T> bit[2];
    BIT(ll n_) { init(n_); }
    void init(ll n_) {
        n = n_ + 1;
        for (ll p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(ll p, ll i, T x) {
        for (ll idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(ll l, ll r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    T sum_sub(ll p, ll i) {
        T s(0);
        for (ll idx = i; idx > 0; idx -= (idx & -idx)) s += bit[p][idx];
        return s;
    }
    T sum(ll i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
    T query(ll l, ll r) { return sum(r - 1) - sum(l - 1); }
    T value(ll i) { return sum(i) - sum(i - 1); }
    //単調性を満たす場合のみ利用可能
    ll binarySearch(ll key) {
        ll left = 0;
        ll right = n + 1;
        while (right - left > 1) {
            ll mid = left + (right - left) / 2;
            if (value(mid) >= key) right = mid;
            else left = mid;
        }
        /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
        return right;
    }
};
int main() {
	ll D, A;
	cin >> N >> D >> A;
	vpll M(N);
	for (i = 0; i < N; i++) {
		cin >> M[i].first >> M[i].second;
	}
	sort(M.begin(), M.end());
    BIT<ll> B(N);
    vl X(N);
    map<ll,ll> Xz;
	for (i = 0; i < N; i++) {
        B.add(i + 1, i + 2, M[i].second);
        X[i] = M[i].first;
        Xz[M[i].first] = i + 1;
	}
    for (i = 0; i < N; i++) {
        ll left = i + 1;
        ll right = left;
        if (X[N - 1] <= X[i] + 2 * D) right = N;
        else {
            right = Xz[*upper_bound(X.begin(), X.end(), X[i] + 2 * D)] - 1;
        }
        if (B.value(i + 1) > 0) {
            ll P = (B.value(i + 1) - 1) / A + 1;
            ans += P;
            B.add(left, right + 1, -P * A);
        }
    }
    co(ans);
}