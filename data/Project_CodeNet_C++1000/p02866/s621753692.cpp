#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  
  if(D[0] != 0) {
    cout << 0 << endl;
    return 0;
  }
  
  sort(all(D));
  
  int ans = 1;
  vector<int> num(N, 0);
  
  
  num[D[0]]++;
  rep(i, N) {
    if(i == 0) continue;
    if(D[i] == 0 || num[D[i]-1] == 0) {
      cout << 0 << endl;
      return 0;
    }
    num[D[i]]++;
    ans *= num[D[i]-1];
    ans %= 998244353;
  }
  cout << ans << endl;
    
  
}