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

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N, P;
string S;

void input() {
	cin >> N >> P;
	cin >> S;
}

void daminput() {
}

int modpow(int base, int p) {
	if (p == 0)return 1;
	if (p == 1)return base % P;
	int ans = modpow(base, p >> 1);
	ans = (ans * ans) % P;
	if (p & 1)ans = (ans * base) % P;
	return ans;
}

void solve() {
	reverse(S.begin(), S.end());
	LL ans = 0;
	VI VS(N + 1, 0);
	for (int n = 1; n <= N; n++)
	{
		VS[n] = S[n - 1] - '0';
	}
	if (P == 2 || P == 5) {
		for (int n = 1; n <= N; n++)
		{
			if (VS[n] % P == 0) {
				ans += (N-n+1);
			}
		}
	}
	else {
		VI memo(P, 0);
		memo[0]++;
		int sum = 0;
		for (int n = 1; n <= N; n++)
		{
			sum += (modpow(10, n) * VS[n]) % P;
			sum %= P;
			ans += memo[sum];
			memo[sum]++;
		}
	}
	cout << ans << "\n";
}
