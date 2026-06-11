#include<bits/stdc++.h>
using namespace std;

signed main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for(int i=0; i<N; i++) cin >> L[i];

  int ans = 0, d = 0;
  for(int i=0; i<=N; i++) {
    if(d <= X) ans++;
    d += L[i];
  }
  cout << ans << endl;
}
