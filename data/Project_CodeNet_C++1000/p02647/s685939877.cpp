//#pragma warning(disable:4996)
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
const long long INF = 1e15;
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N,K;
	cin >> N >> K;
	VI A[2];
	A[0].resize(N + 2, 0);
	A[1].resize(N + 2, 0);
	for (int n = 1; n <= N; n++)cin >> A[1][n];
	int last = -1;
	for (int k = 0; k < K; k++) {
		int t = k % 2;
		int rev = 1 - t;
		for (int n = 0; n <= N + 1; n++)A[t][n] = 0;
		for (int n = 1; n <= N; n++) {
			A[t][max(1, n - A[rev][n])]++;
			A[t][min(N + 1, n + A[rev][n] + 1)]--;
		}
		bool nonNflag = false;
		for (int n = 1; n <= N; n++) {
			A[t][n] += A[t][n - 1];
			if (A[t][n] != N)nonNflag = true;
		}
		last++;
		if (!nonNflag)break;
	}
	for (int n = 1; n <= N; n++) {
		cout << A[last & 1][n] << " ";
	}
	cout << "\n";
	return 0;
}