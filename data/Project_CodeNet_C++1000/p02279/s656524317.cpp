#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a), i##_len=(n); i>i##_len; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
constexpr int MAX = 100005;
constexpr int NIL = -1;
struct Node {
	int p, l, r;
};
Node T[MAX];
int D[MAX];
inline void rec(int u, int p) {
	D[u] = p;
	if(T[u].r != NIL) rec(T[u].r, p);
	if(T[u].l != NIL) rec(T[u].l, p + 1);
}
int main() {
	int n; cin >> n;
	rep(i, 0, n) T[i].p = T[i].l = T[i].r = NIL;
	int v, d, c, l;
	rep(i, 0, n) {
		cin >> v >> d;
		rep(j, 0, d) {
			cin >> c;
			if(j == 0) T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	int r;
	rrep(i, n - 1, -1) {
		if(T[i].p == NIL) { r = i; break; }
	}
	rec(r, 0);
	rep(u, 0, n) {
		cout << "node " << u << ": ";
		cout << "parent = " << T[u].p << ", ";
		cout << "depth = " << D[u] << ", ";
		if(T[u].p == NIL) p("root, ");
		else if(T[u].l == NIL) p("leaf, ");
		else p("internal node, ");
		p("[");
		for (int i = 0, c = T[u].l; c != NIL; ++i, c = T[c].r) {
			if (i) p(", ");
			p(c);
		}
		P("]");
	}
	return 0;
}