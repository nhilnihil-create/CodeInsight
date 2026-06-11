#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int A, B, M;
  cin >> A >> B >> M;
  
  int i = 0;
  vector<int> a(A), b(B), x(M), y(M), c(M);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  rep(i, M) {
    cin >> x[i] >> y[i] >> c[i];
  }
  
  int mina = a[0], minb = b[0];
  rep(i, A) {
    if(a[i] < mina) mina = a[i];
  }
  rep(i, B) {
    if(b[i] < minb) minb = b[i];
  }
  
  int ans = mina + minb;
  
  rep(i, M) {
    if(a[x[i]-1] + b[y[i]-1] - c[i] < ans) ans = a[x[i]-1] + b[y[i]-1] - c[i];
  }
  
  
  
  cout << ans << endl;
  
}
