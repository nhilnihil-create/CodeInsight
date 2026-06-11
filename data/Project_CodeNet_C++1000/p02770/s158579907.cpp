#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  ll k, q;
  cin >> k >> q;
  ll d[k];
  rep(i,k)
  {
    cin >> d[i];
  }
  rep(i,q)
  {
    int n, x, m;
    cin >> n >> x >> m;
    ll d1 = 0, eq1 = 0,dm;
    n = n - 1;
    int nkm = n % k;
    int nkd = (n / k);
    rep(j,k)
    {
      dm=d[j] % m;
      if (dm) {
        d1 += dm * nkd;
        if (j < nkm) {
          d1 += dm;
        }
      } else {
        eq1 += nkd;
        if (j < nkm) {
          eq1++;
        }
      }
    }
    d1 += x;
    cout << n - (d1 / m - x / m) - eq1 << endl;
  }
}