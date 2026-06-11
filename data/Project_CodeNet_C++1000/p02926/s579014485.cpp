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


struct Henkaku {
  ld first;
  complex<ld> second;
};

bool operator< (Henkaku &h1, Henkaku &h2) {
  return h1.first < h2.first;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(11);

  int n; cin >> n;
  vector<Henkaku> v;
  for(int i=0;i<n;++i) {
    int x, y; cin >> x >> y;
    //if(x == 0 && y == 0) continue;
    v.push_back({0.0, complex<ld>(0, 0)});
    v[i].second = complex<ld>(x, y);
    
    v[i].first = arg(v[i].second);
    //cout << v[i].first << " " << v[i].second << endl;
  }
  n = SZ(v);
  sort(v.begin(), v.end());
  
  
  
  ld ma = 0;
  for(int i=0;i<n;++i) {
    complex<ld> now(0, 0);
    for(int j=0;j<n;++j) {
      now += v[(i+j)%n].second;
      ma = max(ma, sqrt(now.real() * now.real() + now.imag() * now.imag()));
      //cout << sqrt(now.real() * now.real() + now.imag() * now.imag()) << endl;
    }
  }
  cout << ma << endl;
  

}
