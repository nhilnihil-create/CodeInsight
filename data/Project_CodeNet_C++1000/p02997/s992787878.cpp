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
void chmax(LL& a, LL b) {
	a = max(a, b);
}
//////////////

void solve() {
	int N,K;
	cin >> N>>K;
	int ansMax = (N - 1) * (N - 2) / 2;//☆ウニ☆
	if (K > ansMax) {
		cout << -1 << endl;
		return;
	}
	//ウニのために辺がN-1個ある。
	//ウニはansMax個最短距離が2
	int ter = ansMax - K;
	int M = N - 1 + ter;
	cout << M << endl;
	for (int i = 1; i < N; ++i) {
		cout << i << " " << N << endl;
	}
	int cnt = 0;
	for (int i = 1; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (cnt >= ter) {
				return;
			}
			cout << i << " " << j << endl;
			++cnt;
		}
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
