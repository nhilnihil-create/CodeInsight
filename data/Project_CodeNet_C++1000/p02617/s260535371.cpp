// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)
#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define len(s) (int)(s).size()
// #define endl '\n'
 
 
inline void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
 
template<class T> ostream& operator<< (ostream& out, const pair<int, int>&X) {
    out << X.first << ' ' << X.second << endl;
    return out;
}
 
template<class T> ostream& operator<< (ostream& out, const vector<T> &X) {
    for (const auto& it : X)
        out << it << ' ';
    return out;
}
template<class T> ostream& operator<< (ostream& out, const set<T> &X) {
    for (const auto& it : X)
        out << it << ' ';
    return out;
}
template<class T> void dbg(const T &X) {
    cerr << "DEBUG: " << ": ";
    cerr << X << endl;
}
 
const int MOD1 = 1e9 + 7;
const int N = 3e5;
const int MOD2 = 998244353;
const int inf = 1e13;
const int mx = (1 << 19) - 1;
const int mod = 1e9 + 7;
vector<int>g[N];

class SegTree {
public:
	SegTree(int n) {
		sz = n;
		t.resize(4 * n);
		add.resize(4 * n);
	}
	void Add(int l, int r, int x) {
		AddOnRange(1, 0, sz - 1, l, r, x);
	}
	int getsum() {
		return t[1];
	}
	void out() {
		dfs(1, 0, sz - 1);
		cout << endl;
	}
	~SegTree() {
		t.clear();
		add.clear();
	}
private:
	int sz;
	vector<int>add;
	vector<int>t;
	int getlen(int l, int r) {
		return r - l + 1;
	}
	void addition(int v, int x, int ln) {
		t[v] += ln * x;
		add[v] += x;
	}
	void push(int v, int ln1, int ln2) {
		add[2 * v] += add[v];
		add[2 * v + 1] += add[v];
		t[2 * v] += add[v] * ln1;
		t[2 * v + 1] += add[v] * ln2;
		add[v] = 0;
	}
	int foo(int x, int y) {
		return x + y;
	}
	void AddOnRange(int v, int tl, int tr, int l, int r, int x) {
		if (tl > r || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			addition(v, x, getlen(tl, tr));
			return;
		}
		int tm = (tl + tr) / 2;
		push(v, getlen(tl, tm), getlen(tm + 1, tr));
		AddOnRange(2 * v, tl, tm, l, r, x);
		AddOnRange(2 * v + 1, tm + 1, tr, l, r, x);
		t[v] = foo(t[2 * v], t[2 * v + 1]);
	}
	void dfs(int v, int tl, int tr) {
		if (tl == tr) {
			cout << t[v] << ' ';
			return;
		}
		int tm = (tl + tr) / 2;
		push(v, getlen(tl, tm), getlen(tm + 1, tr));
		dfs(2 * v, tl, tm);
		dfs(2 * v + 1, tm + 1, tr);
	}
};



 
signed main() {
    accell();
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if (a > b)
			swap(a, b);
		g[b].push_back(a);
	}
	SegTree t(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		t.Add(0, i, 1);
		for (int p : g[i]) {
			t.Add(0, p, -1);
		}
		ans += t.getsum();
	}
	cout << ans << endl;
    return 0;	
}
