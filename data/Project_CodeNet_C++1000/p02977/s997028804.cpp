#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;

  int cnt = 0;
  int tmpn = n;
  int a = 0;
  int now = 1;
  while(tmpn) {
    if(tmpn & 1) {
      cnt++;
      a = now;
    }
    tmpn >>= 1;
    now <<= 1;
  }
  if(cnt == 1) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "Yes" << endl;
  }

  int b = n ^ 1 ^ a;

  for(int i=2;i<n;i+=2) {
    if(i == 2) cout << n+1 << " " << i << endl;
    cout << i << " " << i+1 << endl;
    cout << i+1 << " " << 1 << endl;
    cout << 1 << " " << n+i << endl;
    cout << n+i << " " << n+i+1 << endl;
  }

  if(n % 2 == 0) {
    if(a % 2) cout << n << " " << a << endl;
    else cout << n << " " << n + a << endl;

    if(b % 2) cout << 2*n << " " << b << endl;
    else cout << 2*n << " " << n + b << endl;
  }

}






















