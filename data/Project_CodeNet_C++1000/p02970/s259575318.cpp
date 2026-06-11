#include<bits/stdc++.h>
using namespace std;

signed main() {
  int N,D; cin >> N >> D;
  int ans = 1;
  int cover=1+2*D;
  for (int i=1; i<=N; i++) {
    if(cover >= i) continue;
    cover = i+2*D;
    ans++;
  }
  cout << ans << endl;
  
}
