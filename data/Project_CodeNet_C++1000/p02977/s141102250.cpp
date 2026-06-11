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

template<typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  int tmp = 1;
  while (tmp < n) tmp *= 2;
  if (tmp == n) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  if (n % 2) {
    vector<bool> sel(n, false);
    bool one = false;
    FOR(i, 2, n + 1) {
      if (sel[i]) continue;
      int j = i ^1;
      sel[i] = true;
      sel[j] = true;
      cout << i << " " << j << endl;
      cout << j << " " << 1 << endl;
      cout << "1 " << i + n << endl;
      cout << i + n << " " << j + n << endl;

      if (!one) {
        cout << 1 + n << " " << i << endl;
        one = true;
      }
    }
  } else {
    int idx = n ^ 1;
    vector<bool> sel(n, false);
    vector<bool> beg(n, false);
    bool one = false;
    FOR(i, 2, n) {
      if (sel[i]) continue;
      beg[i] = true;
      int j = i ^1;
      sel[i] = true;
      sel[j] = true;
      cout << i << " " << j << endl;
      cout << j << " " << 1 << endl;
      cout << 1 << " " << i + n << endl;
      cout << i + n << " " << j + n << endl;
      if(!one) {
        cout << 1 + n << " " << i << endl;
        one = true;
      }
    }
    FOR(i, 2, n) {
      if(i == idx) continue;
      int j = idx ^ i;
      if(j != i && j < n) {
        cout << n << " " << (beg[i] ? i+n : i) << endl;
        cout << 2*n << " " << (beg[j] ? j+n : j) << endl;
        break;
      }
    }
  }


}






