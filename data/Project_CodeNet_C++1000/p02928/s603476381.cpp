#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int ans = 0;
  int mod = pow(10, 9)+7;
  
  int sk = K*(K-1)/2;
  sk %= mod;
  
  rep(i, N) {
    int k = 0;
    int kk = 0;
    rep(j, N) {
      if(A[i] > A[j]) {
        kk++;
        if(i < j) k++;
      }
    }
    ans += k*K;
    ans %= mod;
    ans += kk*sk;
    ans %= mod;
  }
  cout << ans << endl;

}