#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

class UnionFind {
public:
    vector <int> par;
    vector <int> siz;

    UnionFind(int sz_): par(sz_), siz(sz_, 1LL) {
        for (int i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (int i = 0; i < sz_; ++i) par[i] = i;
    }

    int root(int x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

signed main() {
  int N, M;
  cin >> N >> M;

  UnionFind uf(N);

  REP(i, M){
    int u, v;
    cin >> u >> v;
    u--; v--;
    uf.unite(u, v);
  }

  set<int> s;
  REP(i, N){
    s.insert(uf.root(i));
  }

  cout << s.size()-1 << "\n";

  return 0;
}
