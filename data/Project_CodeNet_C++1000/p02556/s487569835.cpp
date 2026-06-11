#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int LIM = 1000000000+10;
const ll oo = 1ll<<60;
struct SegTree{
  ll v;
  SegTree *der, *izq;
  SegTree() : v(-oo), der(NULL), izq(NULL){}
};

void Update(SegTree& nodo, int a, ll v, int L = 0, int R = LIM ) {
  if ( L > a || R < a)  return;
  if (a == L && a == R){
    nodo.v = max(nodo.v,v); 
    return;
  }
  if (!nodo.izq) {
    nodo.izq = new SegTree();
    nodo.der = new SegTree();
  }
  int m = (L+R)>>1;
  Update(*nodo.izq, a, v, L, m);
  Update(*nodo.der, a, v, m+1, R);
  nodo.v = max(nodo.izq->v, nodo.der->v);
}

ll Query(SegTree& nodo, int l, int r, int L=0, int R = LIM) { 
  if (L > r || R < l)  return -oo;
  if ( L >= l && R <= r) return nodo.v;
  int m = (L+R)>>1;
  if (!nodo.izq) {
    nodo.izq = new SegTree();
    nodo.der = new SegTree();
  }
  return  max(Query(*nodo.izq, l, r, L, m),
          Query(*nodo.der, l, r, m + 1, R));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<ii> puntos;
	SegTree st1 = SegTree();
	SegTree st2 = SegTree();
	forn(i,0,N){
		int x,y; cin >> x >> y;
		puntos.pb({x,y});
	}
	sort(all(puntos));
	ll res = 0;
	forr(i,N-1,0){
		ll maxi1 = Query(st1,puntos[i].se,LIM)-puntos[i].fi-puntos[i].se;
		ll maxi2 = Query(st2,1,puntos[i].se)-puntos[i].fi+puntos[i].se;
		res = max(res,maxi1);
		res = max(res,maxi2);
		Update(st1,puntos[i].se,puntos[i].fi+puntos[i].se);
		Update(st2,puntos[i].se,puntos[i].fi-puntos[i].se);
	}
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
