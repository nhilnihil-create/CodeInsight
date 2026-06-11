/*{{{*/
#include<bits/stdc++.h>
#define sz(X) ((int)(X).size())
#define all(X) (X).begin(), (X).end()
#define rep(I, A, B) for (int I = (A); I <= (B); ++I)
#define repr(I, A, B) for (int I = (A); I >= (B); --I)
#define fors(I, S) for (int I = 0; S[I]; ++I)
#define get_pos(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define mp make_pair
#define pb emplace_back
#define ms0(X) memset((X), 0, sizeof((X)))
#define ms1(X) memset((X), -1, sizeof((X)))
#define len(X) strlen(X)
#define in insert
#define cn count
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<int> si;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T, class U> void _W(const pair<T, U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
#define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
#define DEBUG(...)
#endif
int MOD = 1e9 + 7;
/*}}}*/
void solve() {
	int n, k;
	R(n, k);
	vi v(n);
	rep(i, 0, n - 1) R(v[i]);
	sort(all(v));
	reverse(all(v));
	if (k >= n) {
		W(0);
		return;
	}
	ll an = 0;
	rep(i, k, n - 1) {
		an += v[i];
	}
	W(an);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#define MULTITEST 0
#if MULTITEST
	CASET {
		solve();
	}
#else
	solve();
#endif
	return 0;
}
