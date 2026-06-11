#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n, k;
  cin >> n >> k;
  int p[n], c[n];
  rep(i,n) cin >> p[i];
  rep(i,n) p[i]--;
  rep(i,n) cin >> c[i];
  
  int ms = (int)-1e10;
  rep(i,n) {
    int da[n], ds[n];
    rep(i,n) da[i] = -1;
    
    int a = i, s = 0;
    rep(j,k) {
      int rk = k - j, ll = j - da[a];
      if(da[a] != -1 && rk > ll) {
        int lc = rk / ll - 1, nk = rk - ll * lc;
        s += (s - ds[a]) * lc;
        rep(j,nk) {
          a = p[a];
          s += c[a];
          ms = max(ms, s);
        }
        break;
      }
      da[a] = j;
      ds[a] = s;
      a = p[a];
      s += c[a];
      ms = max(ms, s);
    }
  }
  cout << ms << endl;
  return 0;
}