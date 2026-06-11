//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int Q = 55;

//head

int n, m, q;
int a[Q], b[Q], c[Q], d[Q];

int dfs(int i, vi& x) {
  if(!i) {
    int res = 0;
    rep(k, q) {
      if(x[b[k]]-x[a[k]] == c[k]) res += d[k];
    }
    return res;
  }
  int res = 0;
  int nn;
  if(x.empty()) nn = 1;
  else nn = x[x.size()-1];
  for(int j = nn; j <= m; j++) {
    x.emplace_back(j);
    chmax(res, dfs(i-1, x));
    x.pop_back();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i, q) {
    a[i]--;
    b[i]--;
  }

  vi j;
  cout << dfs(n, j) << endl;

}