//#pragma warning(disable:4996)
//#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;
template<class T>
using pqueue = priority_queue<T, vector<T>, function<bool(T, T)>>;

template<class T>
inline void chmin(T& a, T b) {
	a = min(a, b);
}

template<class T>
inline void chmax(T& a, T b) {
	a = max(a, b);
}

void input();
void solve();

void daminput();
void naive();

void outputinput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	//naive();
	//outputinput();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N, Q;
VI T, U, V;

void input() {
	cin >> N >> Q;
	T.resize(Q);
	U.resize(Q);
	V.resize(Q);
	for (int n = 0; n < Q; n++) {
		cin >> T[n] >> U[n] >> V[n];
	}
}

void daminput() {
}

//unionFind
class unionFind {
private:
	int* p;   //親配列のポインタ
	int* rank;
	int N;   //要素数
	int* check;   //同値な要素の数
public:
	unionFind(int);   //コンストラクタ
	int parent(int);   //親要素を返す
	void unit(int, int);   //2要素をつなぐ
	int operator[](int);   //parentの省略形
	~unionFind();
	int size(int n);   //頂点nと同値な要素数を返す
};

unionFind::unionFind(int n) {
	N = n;
	p = new int[N];
	rank = new int[N];
	for (int i = 0; i < N; i++) {
		p[i] = i;
		rank[i] = 0;
	}
	check = new int[N];
	for (int n = 0; n < N; n++)check[n] = 1;
	return;
}

int unionFind::parent(int n) {
	if (n < 0 || n >= N)return -1;
	if (p[n] == n)return n;   //自分が一番上の親
	return p[n] = parent(p[n]);   //つなぎ直しと上にたどる操作
}

int unionFind::operator[](int n) {
	return parent(n);
}

void unionFind::unit(int x, int y) {
	x = parent(x), y = parent(y);
	if (x == y)return;   //根が同じだから何もせずに帰る
	int sum = check[x] + check[y];
	if (rank[x] < rank[y])p[x] = y;
	else {
		p[y] = x;
		if (rank[x] == rank[y])rank[x]++;
	}
	check[x] = sum;
	check[y] = sum;
	return;
}

unionFind::~unionFind() {
	delete(p);
	delete(rank);
	delete(check);
	return;
}

int unionFind::size(int n) {
	return check[parent(n)];
}

void solve() {
	unionFind UF(N);
	for (int n = 0; n < Q; n++) {
		if (T[n] == 0) {
			UF.unit(U[n], V[n]);
		}
		else {
			if (UF[U[n]] == UF[V[n]]) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
	}
}

void naive() {
}

void outputinput() {
}