#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll L, R, mod=2019;
  cin >> L >> R;
  ll m=10000;
  if (R-L>=2019) {
    cout << 0 << endl;
  }
  else {
    R=R-L/mod*mod;
    L=L-L/mod*mod;
    for (ll i=L; i<=R; i++) {
      for (ll j=i+1; j<=R; j++) {   
        ll n=i*j;
        m=min(m, n-n/mod*mod);
      }
    }
    cout << m << endl;
  }
}