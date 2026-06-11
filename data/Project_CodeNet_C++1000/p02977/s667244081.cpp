# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;// ;//1000000000 + 7 998244353 924844033 1000000000 + 9;
constexpr long long INF = numeric_limits<LL>::max() / 100;
constexpr long long DINF = 1000000000000;
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<double, double> Dll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<LL>>g;
vector<edge>ed;
vector<Pll>pv;
map<Pll, LL>ma;
set<LL>st;
vector<LL>rest;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
LL n, m, k, p, q, w, h, s, t, ans, cnt, sum, a[310000], b[310000], sub[210000];
string str;
bool f;
char c[1100][1100];
int main() {
	cin >> n;
	t = n;
	while (t) {
		if (t == 1) {
			cout << "No" << endl;
			return 0;
		}
		if (t % 2 != 0)break;
		t /= 2;
	}
	cout << "Yes" << endl;
	m = n;
	n++;
	while (n > 1) {
		n /= 2;
		cnt++;
	}
	n = m;
	rep(i, (1LL << cnt) - 2) {
		cout << i + 1 << " " << i + 2 << endl;
	}
	cout << ((1LL << cnt) - 1) << " " << n + 1 << endl;
	rep(i, (1LL << cnt) - 2) {
		cout << n + i + 1 << " " << n + i + 2 << endl;
	}
	m = n - ((1LL << cnt) - 1);
	LL cur = (1LL << cnt) - 1;
	cur++;
	rep(i, m / 2) {
		cout << cur << " " << 1 << endl;
		cout << cur + 1 << " " << 1 << endl;
		cout << cur + 1 << " " << cur + n << endl;
		cout << cur << " " << cur + 1 + n << endl;
		cur+=2;
	}
	if (n % 2 == 0) {
		rep(i, n) {
			if ((1 << i)&n) {
				if (i == 1) {
					cout << n - 1 << " " << n << endl;
					cout << ((n - 2) ^ n) << " " << n * 2 << endl;
				}
				else {
					cout << (n ^ (1 << i)) << " " << n << endl;
					cout << (1 << i) << " " << n * 2 << endl;
				}
				break;
			}
		}
	}
	return 0;
}