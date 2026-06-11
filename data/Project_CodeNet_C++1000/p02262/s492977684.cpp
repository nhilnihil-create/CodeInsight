#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
int insersionsort(vector<int>&a, int g) {
	int ret(0);
	rep(i, g, a.size()) {
		int v = a[i];
		int j = i - g;
		while (0 <= j&&a[j] > v) {
			a[j + g] = a[j];
			ret++;
			j -= g;
		}
		a[j + g] = v;
	}
	return ret;
}
void shellsort(vector<int>&a) {
	vector<int>G;
	for (int x = 1; x <= a.size(); x = 3 * x + 1)G.push_back(x);
	reverse(all(G));
	int cnt(0);
	rep(i, 0, G.size())cnt += insersionsort(a, G[i]);
	cout << G.size() << endl;
	rep(i, 0, G.size())cout << G[i] << (i == G.size() - 1 ? '\n' : ' ');
	cout << cnt << endl;
	rep(i, 0, a.size())cout << a[i] << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	shellsort(a);
	return 0;
}