#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int X, K, D; cin >> X >> K >> D;
  if(X < 0) X = -X;
  if(X/D >= K) cout << X-K*D << endl;
  else {
    int k = X/D;
    X -= k*D;
    K -= k;
    if(K%2 == 0) cout << X << endl;
    else cout << abs(X-D) << endl;
  }
    

}
