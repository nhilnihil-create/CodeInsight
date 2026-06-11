#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}

template<typename T>
void IN(vector<T> &A,int N=-1) {
	if (N == -1) {
		N = A.size();
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
}

template<typename T>
void SO(vector<T> &A,bool F=false) {
	sort(A.begin(), A.end());
	if (F) {
		reverse(A.begin(), A.end());
	}
}
//////////////
//最大公約数
LL gcd(LL a, LL b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

//最小公倍数
LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

int f(LL a) {
	int cnt = 0;
	while (a % 2 == 0) {
		a /= 2;
		++cnt;
	}
	return cnt;
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<LL> A(N);
	
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ter = f(A[0]);
	
	for (int i = 1; i < N; ++i) {
		if (ter != f(A[i])) {
			cout << 0 << endl;
			return;
		}
	}
	for (int i = 0; i < N; ++i) {
		while (A[i] % 2 == 0) {
			A[i] /= 2;
		}
	}
	LL AA = A[0];
	for (int i = 1; i < N; ++i) {
		AA = lcm(AA, A[i]);
	}
	while (ter > 1) {
		AA *= 2;
		--ter;
	}
	cout << M / AA  - M/(AA*2)<< endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
