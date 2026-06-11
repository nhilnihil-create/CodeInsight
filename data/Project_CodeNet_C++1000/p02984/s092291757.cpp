#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll x2 = 0;
	rep(i, n) {
		if(i%2) x2 -= a[i];
		else x2 += a[i];
	}
	vector<int> ans(n);
	ans[0] = x2 / 2;
	rep(i, n-1) {
		ans[i+1] = a[i] - ans[i];
	}
	rep(i, n) ans[i] *= 2;
	rep(i, n) printf("%d%c", ans[i], i == n-1? '\n':' ');
    return 0;
}
