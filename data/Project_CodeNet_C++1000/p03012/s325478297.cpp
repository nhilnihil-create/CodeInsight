#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  rep(i,n) cin >> w[i];
  for(int i = 1; i < n; i++) w[i] += w[i-1];
  int ans = w[n-1];
  rep(i,n) ans = min(ans,abs(w[n-1]-2*w[i]));
  cout << ans << endl;
  return 0;
}