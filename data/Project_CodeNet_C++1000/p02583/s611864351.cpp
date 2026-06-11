#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  
  int ans = 0;
  rep(i, N) rep(j, N) rep(k, N) {
    if(i == j || j == k || k == i || L[i] == L[j] || L[j] == L[k] || L[k] == L[i]) continue;
    if(abs(L[i]-L[j]) < L[k] && L[k] < L[i]+L[j]) ans++;
  }
  cout << ans / 6 << endl;

}
