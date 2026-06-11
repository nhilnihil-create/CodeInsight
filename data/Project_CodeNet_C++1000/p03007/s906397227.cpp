#include <bits/stdc++.h>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/irange.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::irange;
using boost::algorithm::join;

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;

constexpr ll MOD = 1e9+7;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/4;
constexpr int INF=inf<int>;
constexpr ll LINF=inf<ll>;

#define Sort(x) sort(begin(x),end(x))
#define Reverse(x) reverse(begin(x),end(x))
#define ABS(a,b) ((a)<(b)?(b)-(a):(a)-(b))
#define nbit(n) (1ull<<(n))
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...) _ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,v) REP(i,(v).size())

// sort(begin(x), end(x), greater<ll>());
// lower_bound(a.begin(), a.end(), val): a[i] ≥ valである最左の位置
// upper_bound(a.begin(), a.end(), val): a[i] > valである最左の位置

// Returns minimum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

// Returns maximum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

template <typename T>
void dumpContents(const T& v, const string& msg)
{
  cerr << "### " << msg << " ###\n";
  for (const auto& x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(20)<<fixed;
    #define endl "\n"
  }
} before_main_function;

// ========== end of template ==========
int N;

// pは最右+の要素のindex
void print(const vi& A, int p) {
  ll sum = accumulate(begin(A), begin(A)+p+1, 0) - accumulate(begin(A)+p+1, end(A), 0);
  cout << sum << endl;

  ll c = A[p+1];
  for (int i=p+1; i>=2; i--) {
    cout << c << " " << A[i-1] << endl;
    c = c - A[i-1];
  }
  cout << A[0] << " " << c << endl;
  c = A[0] - c;
  for (int i=p+2; i<N; i++) {
    cout << c << " " << A[i] << endl;
    c = c - A[i];
  }
}

int main(int argc, char** argv) {
  cin >> N;
  vi A(N);
  for (auto& a : A) {
    cin >> a;
  }

  sort(begin(A), end(A), greater<ll>());

  if (A[N-1] >= 0) {
    print(A, N-2);
    return 0;
  }

  if (A[0] <= 0) {
    print(A, 0);
    return 0;
  }

  REP(i, N) {
    if (A[i] < 0) {
      print(A, i-1);
      break;
    }
  }

  return 0;
}
