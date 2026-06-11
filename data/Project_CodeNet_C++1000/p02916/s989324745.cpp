#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  int ans = 0;
  rep(i,0,n) {
    int b;
    cin >> b;
    ans += b;
  }
  vector<int> c(n);
  rep(i,1,n) cin >> c[i];
  rep(i,0,n-1) {
    if (a[i+1]-a[i] == 1) {
      ans += c[a[i]];
    }
  }
  cout << ans << endl;
  return 0;
}
