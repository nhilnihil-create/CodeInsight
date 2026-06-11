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

vector<int> edge[200010];

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  if(__builtin_popcount(n) == 1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << "\n";
  edge[1].pb(2);
  edge[2].pb(3);
  edge[3].pb(n + 1);
  edge[n + 1].pb(n + 2);
  edge[n + 2].pb(n + 3);
  for(int i = 4; i + 1 <= n; i += 2){
    edge[n + 1].pb(i);
    edge[i].pb(i + 1);
    edge[n + 1].pb(i + n + 1);
    edge[i + n + 1].pb(i + n);
  }
  if(n % 2 == 0){
    int l = 4;
    while(true){
      int r = n ^ 1 ^ l;
      if(r == l || r > n)l++;
      else break;
    }
    int r = n ^ 1 ^ l;
    if(l == 2)edge[n + 2].pb(n);
    else if(l == 3)edge[3].pb(n);
    else if(l % 2 == 0)edge[l].pb(n);
    else edge[l + n].pb(n);
    if(r == 2)edge[n + 2].pb(2 * n);
    else if(r == 3)edge[3].pb(2 * n);
    else if(r % 2 == 0)edge[r].pb(2 * n);
    else edge[r + n].pb(2 * n);
  }
  FOR(i, 1, 2 * n + 1){
    for(auto e: edge[i]){
      cout << min(i, e) << " " << max(i, e) << "\n";
    }
  }
  cout << flush;
  return 0;
}
