// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

ll score(vector<ll> &h, int l, int r, ll base){
  if(r <= l)return 0;
  ll mini = linf, idx = -1;
  ll res = 0;
  for(int i = l; i < r; i++){
    if(mini > h[i]){
      mini = h[i];
      idx = i;
    }
  }
  res += mini - base;
  res += score(h, l, idx, mini);
  res += score(h, idx + 1, r, mini);
  return res;
}

ll score(vector<ll> &h){
  return score(h, 0, sz(h), 0LL);
}

ll dp[2][310][310];

int main(int argc, char const* argv[])
{
  int n, k; cin >> n >> k;
  vector<ll> h(n); cin >> h;
  auto ht = h; ht.pb(0); sort(all(ht)); UNIQUE(ht);
  map<ll, int> mp; rep(i, sz(ht))mp[ht[i]] = i;
  rep(i, 2)rep(j, n + 1)rep(l, k + 1)dp[i][j][l] = linf;
  dp[0][0][0] = 0;
  rep(i, n){
    rep(j, sz(ht)){
      rep(l, k + 1)dp[(i+1)&1][j][l] = linf;
    }
    rep(j, sz(ht)){
      rep(l, k + 1){
        if(dp[(i)&1][j][l] >= linf)continue;
        if(ht[j] >= h[i]){
          chmin(dp[(i+1)&1][mp[h[i]]][l], dp[i&1][j][l]);
          if(l+1<=k)chmin(dp[(i+1)&1][j][l+1], dp[i&1][j][l]);
        }else{
          chmin(dp[(i+1)&1][mp[h[i]]][l], dp[i&1][j][l] + h[i] - ht[j]);
          if(l+1<=k)chmin(dp[(i+1)&1][j][l+1], dp[i&1][j][l]);
        }
      }
    }
  }
  ll res = linf;
  rep(i, sz(ht)){
    rep(j, k + 1)chmin(res, dp[n&1][i][j]);
  }
  cout << res << endl;
  return 0;
}
