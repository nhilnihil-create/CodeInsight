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
	int N, M;
	cin >> N >> M;
	VI check(N, -1);
	for (int m = 0; m < M; m++) {
		int s, c;
		cin >> s >> c;
		s--;
		if (check[s] != -1 && check[s] != c) {
			cout << -1 << "\n";
			return 0;
		}
		check[s] = c;
	}
	if (N != 1) {
		if (check[0] == 0) {
			cout << -1 << "\n";
			return 0;
		}
		if (check[0] == -1)check[0] = 1;
	}
	else {
		if (check[0] == -1)check[0] = 0;
	}
	for (int n = 1; n < N; n++) {
		if (check[n] == -1)check[n] = 0;
	}
	for (int n = 0; n < N; n++)cout << check[n];
	cout << "\n";
	return 0;
}
