#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep (i,n) cin >> a[i];
  vector<int> ans(n);
  
  rep (i,k){
    vector<int> b(n,0);
    rep(j,n){
      int l = max(0,j-a[j]);
      int r = min(n-1,j+a[j]);
      b[l]++;
      if (r+1<n) b[r+1]--;
    }
    for (int j=1;j<(n);j++) b[j]+=b[j-1];
    a = b;
    if (count(a.begin(),a.end(),n) == n) break;
  }
  ans = a;

  rep(i,n) cout << ans[i] << " ";
  return 0;
}
