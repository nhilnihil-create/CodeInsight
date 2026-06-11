#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a); i>n; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
ll cnt = 0;
vi G;
inline void insertionSort(vi& a, int n, int g) {
	rep(i, g, n) {
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j -= g;
			++cnt;
		}
		a[j + g] = v;
	}
}
inline void shellSort(vi& a, int n) {
	int h = 1;
	while(true) {
		G.push_back(h);
		h = 3 * h + 1;
		if(h > n) break;
	}
	rrep(i, len(G) - 1, -1) {
		insertionSort(a, n, G[i]);
	}
}
int main() {
	int n; cin >> n;
	vi v(n); rep(i, 0, n) cin >> v[i];
	shellSort(v, n);
	P(len(G));
	rrep(i, len(G) - 1, -1) cout << G[i] << (i == 0 ? "\n" : " ");
	P(cnt);
	rep(i, 0, n) P(v[i]);
	return 0;
}