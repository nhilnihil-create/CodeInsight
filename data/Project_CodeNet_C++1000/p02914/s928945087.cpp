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


const int MAX_H = 510, MAX_W = 100010;
struct MatrixB {
  int H, W;
  bitset<MAX_W> val[MAX_H];
  MatrixB(int m = 1, int n = 1): H(m), W(n){}
  inline bitset<MAX_W>& operator[](size_t i){return val[i];}
  int gauss_jordan(bool is_extended = false){
    int rank = 0;
    for(int col = 0; col < W; col++){
      if(col == W - 1 && is_extended)break;
      int pivot = -1;
      for(int row = rank; row < H; row++){
        if(val[row][col]){
          pivot = row;
          break;
        }
      }
      if(pivot == -1)continue;
      swap(val[pivot], val[rank]);
      for(int row = 0; row < H; row++){
        if(row != rank && val[row][col])val[row] ^= val[rank];
      }
      rank++;
    }
    return rank;
  }
};

int linear_eq(MatrixB &A, vector<int> b, vector<int> & res){
  int m = A.H, n = A.W;
  MatrixB M(m, n + 1);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      M[i][j] = A[i][j];
    }
    M[i][n] = b[i];
  }
  int rank = M.gauss_jordan(true);

  for(int row = rank; row < m; row++){
    if(M[row][n])return -1;
  }

  res.assign(n, 0);
  for(int i = 0; i < rank; i++)res[i] = M[i][n];
  return rank;
}

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  ll all = 0;
  rep(i, n)all ^= a[i];
  MatrixB M(60, n);
  ll res = 0;
  vector<int> b(60, 0);
  for(int i = 59; i >= 0; i--){
    //int I = 60 + i;
    vector<int> r;
    if((all >> i) & 1){
      res += bit(i);
      //b[I] = 1;
      //b[i] = 1;
    }else{
      rep(j, n){
        M[i][j] = (a[j] >> i) & 1;
        //M[I][j] = (a[j] >> i) & 1;
      }
      b[i] = 1;
      //b[I] = 0;
      int rank = linear_eq(M, b, r);
      if(rank != -1){
        res += (1LL << (i+1));
      }else{
        b[i] = 0;
        //b[I] = 0;
        rep(j, n){
          M[i][j] = 0;
          //M[I][j] = (a[j] >> i) & 1;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
