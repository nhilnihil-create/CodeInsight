#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m, M;
  cin>>n;
  cin >> m >> M;
  int ans = m;
  
  rep (i, n-1) {
    ans+=min(m, M);
    m = M;
    cin>>M;
  }
  cout << ans << endl;
}