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

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9+7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
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
	string S;
	cin >> S;
	int N = S.size();
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[N - i - 1])flag = false;
	}
	for (int i = 0; i < (N - 1) / 2; i++) {
		if (S[i] != S[(N - 1) / 2 - 1 - i])flag = false;
	}
	for (int i = 0; i < N / 2; i++) {
		if (S[i + (N + 1) / 2] != S[N / 2 - i - 1 + (N + 1) / 2])flag = false;
	}
	if (flag)cout << "Yes\n";
	else cout << "No\n";
	return 0;
}