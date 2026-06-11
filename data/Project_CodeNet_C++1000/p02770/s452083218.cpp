#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int k, q; cin >> k >> q;
  vll d(k);
  for(int i=0;i<k;++i) {
    cin >> d[i];
  }

  while(q) {
    q--;
    ll n, x, m; cin >> n >> x >> m;
    vll su1(k+1);
    for(int i=0;i<k;++i) {
      su1[i+1] = su1[i] + d[i] % m;
    }

    vll su2(k+1);
    for(int i=0;i<k;++i) {
      su2[i+1] = su2[i] + (d[i]%m == 0);
    }

    //printv(su1);
    //printv(su2);

    ll su = (n-1)/k * su1[k] + x%m + su1[(n-1)%k];
    ll su0 = (n-1)/k * su2[k] + su2[(n-1)%k];
    //cout << su << ":" << su0 << endl;

    ll ans = n-1;
    ans -= su / m;
    ans -= su0;
    cout << ans << endl;
  }

}
