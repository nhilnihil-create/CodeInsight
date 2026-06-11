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
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;
using lthe = pair<ll, ll>;

template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int main() {
	int n;
	cin >> n;
	Vi A(n + 1);
	rep(i, n + 1)  cin >> A[i];

	if (n == 0) {
		if (A[0] == 1)  cout << 1 << endl;
		else  cout << -1 << endl;
		return 0;
	}

	vector<lthe> lr(n + 1);
	lr[n].first = A[n];
	lr[n].second = A[n];
	for (int i = n - 1; i >= 0; i--) {
		lr[i].second = lr[i + 1].second + A[i];
		lr[i].first = lr[i + 1].first / 2 + lr[i + 1].first % 2 + A[i];
	}

	if (!(lr[0].first <= 1 + A[0] && 1 + A[0] <= lr[0].second)) {
		cout << -1 << endl;
		return 0;
	}
	Vl D(n + 1);
	D[0] = 1;
	bool f = false;
	for (int i = 1; i <= n; i++) {
		D[i] = min(2 * (D[i - 1] - A[i - 1]), lr[i].second);
		if (D[i] < lr[i].first) {
			f = true;
			break;
		}
	}
	if (f) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	rep(i, n + 1)  ans += D[i];
	cout << ans << endl;
}
