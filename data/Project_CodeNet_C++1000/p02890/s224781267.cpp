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
#define R(i,n) for(int i=0;i<(n);i=i+1)
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

void solve() {
	int N;
	cin >> N;
	vector<int>A(N); IN(A);
	vector<int>H(N + 1, 0);
	R(i, N) {
		H[A[i]]++;
	}
	vector<int> B;
	for (int i = 1; i <= N; ++i) {
		if (H[i]) {
			B.push_back(H[i]);
		}
	}
	SO(B);
	vector<int> BB(B.size()+1, 0);
	for (int i = 0; i < B.size(); ++i) {
		BB[i+1] = BB[i] + B[i];
	}
	for (LL k = 1; k <= N; ++k) {
		LL L = 0;
		LL R = N+1;
		while (L + 1 < R) {
			LL T = (L + R) / 2;
			int index = lower_bound(B.begin(), B.end(),T)-B.begin();
			LL cnt = B.size() - index;
			LL res = BB[index] + cnt * T;
			if (res >= T * k) {
				L = T;
			}
			else {
				R = T;
			}
		}
		cout << L << endl;
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}