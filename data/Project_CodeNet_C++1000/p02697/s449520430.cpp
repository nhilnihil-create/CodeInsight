/**
 *  author: MOOONI
 *  hackers are welcome!
**/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define str string
#define pi pair
#define tup tuple
#define vec vector
#define temp template
#define tn typename

#define ff first
#define ss second
#define SZ(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rsz resize
#define ins insert
#define fr front 
#define bc back
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair

#define FOR(i, a, b) for (ll i = (a); i <= (b); i++) 
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define trav(a, x) for (auto &a : x)
#define popcount __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define gcd __gcd

// DEBUG
#define ts to_string
temp<tn A, tn B> str ts(pi<A, B> p);
temp<tn A, tn B, tn C> str ts(tup<A, B, C> p);
str ts(const str& s) { return '"' + s + '"'; }
str ts(const char* s) { return ts((str) s); }
str ts(bool b) { return (b ? "true" : "false"); }
str ts(vec<bool> v) { bool f = true; str res = "{";
FOR(i, 0, static_cast<ll>(v.size()) - 1) 
{ if (!f) res += ", "; res += ts(v[i]);
f = false; } res += "}"; return res; }
temp<size_t N> str ts(bitset<N> v) { str res = "";
trav(a, v) { res += (char) ('0' + a); } return res; }
temp<tn A> str ts(A v) { bool f = true; str res = "{";
trav(x, v) { if (!f) res += ", "; res += ts(x);
f = false; } res += "}"; return res; }
temp<tn A, tn B> str ts(pi<A, B> p) { 
  return "(" + ts(p.ff) + ", " + ts(p.ss) + ")"; }
temp<tn A, tn B, tn C> str ts(tup<A, B, C> t) {
  return "(" + ts(get<0>(t)) + ", " + ts(get<1>(t)) + ", " + ts(get<2>(t)) + ")"; }
void DBG() { cerr << endl; }
temp<tn H, tn... T> void DBG(H h, T... t) { cerr << " " << ts(h); DBG(t...); }
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", DBG(__VA_ARGS__);

// INPUT AND OUTPUT
temp<tn T> void re(T& x) { cin >> x; };
temp<tn H, tn... T> void re(H& h, T&... t) { re(h); re(t...); }
temp<tn T> void pr(T x) { cout << x; };
temp<tn H, tn... T> void pr(H h, T... t) { pr(h); pr(t...); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Do = [&](ll L, ll R, ll &k) {
    while (L < R && k) {
      pr(L, " ", R, '\n');
      --k;
      ++L;
      --R;
    }
  };
  ll n, m;
  re(n, m);
  if (n % 2 == 1) {
    Do(1, n, m);
    return 0;
  }
  Do(1, n / 2, m);
  Do(n / 2 + 2, n, m);
  return 0;
}