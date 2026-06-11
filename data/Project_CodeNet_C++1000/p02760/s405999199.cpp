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
	VVI A;
	A.resize(3, VI(3, 0));
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++)cin >> A[y][x];
	}
	int N;
	cin >> N;
	vector<vector<bool>> check;
	check.resize(3, vector<bool>(3, false));
	for (int n = 0; n < N; n++) {
		int b;
		cin >> b;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (A[y][x] == b)check[y][x] = true;
			}
		}
	}
	for (int x = 0; x < 3; x++) {
		if (check[0][x] && check[1][x] && check[2][x])goto YES;
	}
	for (int y = 0; y < 3; y++) {
		if (check[y][0] && check[y][1] && check[y][2])goto YES;
	}
	if (check[0][0] && check[1][1] && check[2][2])goto YES;
	if (check[0][2] && check[1][1] && check[2][0])goto YES;
	goto NO;
YES:
	cout << "Yes\n";
	return 0;
NO:
	cout << "No\n";
	return 0;
}