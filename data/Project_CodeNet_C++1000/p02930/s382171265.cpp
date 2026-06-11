//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
//#define double long double

using namespace std;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

const int MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 200020;

int ans[502][502];

void solve(vector<int>&v,int base) {
	if (v.size() == 1)return;
	REP(i, v.size()) {
		for (int j = i + 1; j < v.size(); j += 2) {
			ans[v[i]][v[j]] = base;
		}
	}
	vector<int>v1, v2;
	REP(i, v.size()) {
		if (i % 2 == 0) {
			v1.pb(v[i]);
		}
		else {
			v2.pb(v[i]);
		}
	}
	solve(v1, base + 1);
	solve(v2, base + 1);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int>v;
	REP(i, N) {
		v.pb(i);
	}
	solve(v, 1);

	REP(i, N - 1) {
		FOR(j, i + 1, N) {
			pe(ans[i][j]);
		}cout << endl;
	}
}
