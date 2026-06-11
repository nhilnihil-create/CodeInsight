#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> prime(int N) {
  vector<bool> a(N, true);
  for(int i=1; i<sqrt(N); i++) {
    if(a[i]) for(int k=2; (i+1)*k-1<N; k++) a[(i+1)*k-1] = false;
  }
  vector<int> p;
  rep(i, N) if(a[i]) p.push_back(i+1);
  p.erase(p.begin());
  return p;
}

signed main() {
  int H, N; cin >> H >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  
  vector<int> dp(H+1, 0);
  
  rep(i, H+1) {
    if(i == 0) continue;
    int a = dp[i-1] + 100000;
    rep(j, N) {
      if(i < A[j]) a = min(a, B[j]);
      else a = min(a, dp[i-A[j]]+B[j]);
    }
    dp[i] = a;
  }
  
  cout << dp[H] << endl;

}