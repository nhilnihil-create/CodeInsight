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
//////////////

void solve() {
	int N, T;
	cin >> N >> T;

	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	
	vector<vector<int>>DP1(N+2, vector<int>(T+1,-INF));
	vector<vector<int>>DP2(N+2, vector<int>(T + 1, -INF));
	for (int t = 0; t <= T; ++t) {
		DP1[0][t] = 0;
		DP2[N + 1][t] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		for (int t = 0; t < T; ++t) {//注文可能
			if (DP1[i - 1][t] >= 0) {//ある。
				//注文しない
				DP1[i][t] = max(DP1[i][t], DP1[i - 1][t]);

				//注文する
				int TT = t + A[i - 1];
				if (TT > T) {
					TT = T;
				}
				DP1[i][TT] = max(DP1[i][TT], DP1[i - 1][t] + B[i - 1]);
			}
		}
		DP1[i][T] = max(DP1[i][T], DP1[i - 1][T]);
	}

	for (int i = N; i >= 1; --i) {
		for (int t = 0; t < T; ++t) {//注文可能
			if (DP2[i + 1][t] >= 0) {//ある。
				//注文しない
				DP2[i][t] = max(DP2[i][t], DP2[i + 1][t]);

				//注文する
				int TT = t + A[i - 1];
				if (TT > T) {
					TT = T;
				}
				DP2[i][TT] = max(DP2[i][TT], DP2[i + 1][t] + B[i - 1]);
			}
		}
		DP2[i][T] = max(DP2[i][T], DP2[i + 1][T]);
	}
	
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int t = 0; t < T; ++t) {
			//T-1の分配
			if (ans < DP1[i - 1][t] + B[i - 1] + DP2[i + 1][T-1-t]) {
				ans = DP1[i - 1][t] + B[i - 1] + DP2[i + 1][T-1-t];
			}
		}
	}
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
