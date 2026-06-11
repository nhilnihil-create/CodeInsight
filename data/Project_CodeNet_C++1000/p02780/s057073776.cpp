#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, K; cin >> N >> K;
  
  vector<double> p(N);
  rep(i, N) cin >> p[i];
  vector<double> e(N);
  rep(i, N) e[i] = (p[i]+1)/2;
  //rep(i, N) cout << e[i] << endl;
  
  double k = 0;
  rep(i, K) k += e[i];
  
  double ans = k;
  for(int i=K; i<N; i++) {
    k += e[i];
    k -= e[i-K];
    ans = max(ans, k);
    //cout << ans << endl;
  }
  cout << fixed << setprecision(10) << ans << endl;

}