#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
#include  <cstdio>
#include  <sstream>
#include  <bitset>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using ld = long double;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vd = vector<double>;
using Vld = vector<long double>;
using Vll = vector<vector<ll> >;
using Vldd = vector<vector<ld> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Pli = pair<ll, int>;
using VPi = vector<Pi>;
using VPl = vector<Pl>;
using VPli = vector<Pli>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int main()
{
	int n, k;
	cin >> n >> k;
	Vi P(n);
	Vl C(n);
	rep(i, n) {
		int t;
		cin >> t;
		t--;
		P[i] = t;
	}
	rep(i, n)  cin >> C[i];



	ll ansmincase = -1e17;
	for (int i = 0; i < n; i++) {
		int u = i;
		ll sum = 0;
		for (int j = 0; j < min(k, 5000); j++) {
			sum += C[P[u]];
			u = P[u];
			ansmincase = max(ansmincase, sum);
		}
	}
	if (k < 5000) {
		cout << ansmincase << endl;
		return 0;
	}

	ll ans = -1e17;
	for (int i = 0; i < n; i++) {
		int u = i;
		ll cirsum = 0;
		ll pathcnt = 0;
		while (1) {
			cirsum += C[P[u]];
			u = P[u];
			pathcnt++;
			if (u == i) break;
		}
		if (cirsum < 0) continue;
		ll tmp = k / pathcnt;
		tmp--;
		ll sum = cirsum * tmp;
		tmp = k % pathcnt;
		int s = i;
		ll tsum = sum;
		for (int c = 0; c < tmp + pathcnt; c++) {
			tsum += C[P[s]];
			s = P[s];
			sum = max(sum, tsum);
		}
		ans = max(ans, sum);
	}
	cout << max(ans, ansmincase) << endl;
	return 0;
}
