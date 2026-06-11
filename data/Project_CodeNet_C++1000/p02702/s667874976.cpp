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
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX / 10000;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	Vi m(n + 1, -1);
	m[0] = 0;
	Vi mod2019(2019, 0);
	mod2019[0]++;
	ll k = 1;
	for (int i = n - 1; i >= 0; i--) {
		k %= 2019;
		m[n - i] = (m[n - i - 1] + k * (s[i] - '0')) % 2019;
		mod2019[m[n - i]]++;
		k *= 10;
	}
	//lrep(i, 1, n + 1)  cout << m[i] << endl;
	ll ans = 0;
	rep(i, 2019) {
		ll tmp = mod2019[i];
		ans += tmp * (tmp - 1) / 2;
	}
	cout << ans << endl;
}
