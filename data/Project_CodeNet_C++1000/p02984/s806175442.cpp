#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,0,n) {
    ll k;
    cin >> k;
    a[i] = k*2;
  }
  vector<ll> b(n+1,0);
  b[0] = a[0];
  rep(i,0,n) {
    b[i+1] = a[i] - b[i];
  }
  ll k = (b[0] - b[n]) / 2;
  rep(i,0,n) {
    if (i % 2 == 0) {
      b[i] -= k;
    } else {
      b[i] += k;
    }
  }
  rep(i,0,n-1) {
    cout << b[i] << " ";
  }
  cout << b[n-1] << endl;
  return 0;
}
