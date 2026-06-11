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

void solve() {
	int N;
	cin >> N;
	vector<LL> A(N+2);
	vector<int> pos(N + 1, 0);
	A[0] = INF; A[N + 1] = INF;
	for (int i = 1; i <=N; ++i) {
		cin >> A[i];
		pos[A[i]] = i;
	}
	set<int> L, R;
	L.insert(-pos[N]);
	R.insert(pos[N]);

	LL ans = 0;
	set<int>::iterator itr;
	for (int i = N - 1; i >= 1; --i) {
		LL ter = pos[i];
		int Lpos2,Lpos1,Rpos1, Rpos2;
		itr = R.upper_bound(ter);
		if (itr != R.end() ){
			Rpos1 = *itr;
			itr = R.upper_bound(Rpos1);
			if (itr != R.end()) {
				Rpos2 = *itr;
			}
			else {
				Rpos2 = N + 1;
			}

			itr = L.upper_bound(-ter);
			if (itr != L.end()) {
				Lpos1 = -(*itr);
			}
			else {
				Lpos1 = 0;
			}
			LL res = (LL)(ter - Lpos1) * (Rpos2 - Rpos1);
			ans += res*i;
		}
		
		itr = L.upper_bound(-ter);
		if(itr != L.end()){
			Lpos1 = -(*itr);
			itr = L.upper_bound(-Lpos1);
			if (itr != L.end()) {
				Lpos2 = -(*itr);
			}
			else {
				Lpos2 = 0;
			}

			itr = R.upper_bound(ter);
			if (itr != R.end()) {
				Rpos1 = (*itr);
			}
			else {
				Rpos1 = N + 1;
			}
			LL res = (LL)(Lpos1 - Lpos2) * (Rpos1 - ter);
			ans += res*i;
		}
		R.insert(ter);
		L.insert(-ter);
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
