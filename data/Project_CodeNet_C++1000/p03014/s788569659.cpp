#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}

int d[2020][2020];
int main() {
  int h, w;
  cin >> h >> w;
 
  vector<string> G(h);
  rep(i, h) cin >> G[i];
  rep(i, h) {
    int cnt = 0, idx = 0;
    rep(j, w) {
      if (G[i][j] == '.') cnt++;
      if (G[i][j] == '#' || j == w - 1) {
        srep(k, idx, j + 1) d[i][k] += cnt;
        cnt = 0;
        idx = j + 1;
      }
    }
  }
  rep(j, w) {
    int cnt = 0, idx = 0;
    rep(i, h) {
      if (G[i][j] == '.') cnt++;
      if (G[i][j] == '#' || i == h - 1) {
        srep(k, idx, i + 1) d[k][j] += cnt;
        cnt = 0;
        idx = i + 1;
      }
    }
  }
  int ans = 0;
  rep(i,h){
    rep(j,w){
      maxs(ans,d[i][j]);
    }
  }
  cout<<ans-1<<endl;
  return 0;
}