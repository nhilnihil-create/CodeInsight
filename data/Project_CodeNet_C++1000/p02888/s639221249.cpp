#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i,0,n) cin >> l[i];
  sort(l.begin(), l.end());
  int ans = 0;
  rep(i,0,n-1) rep(j,i+1,n) {
    int k = lower_bound(l.begin(), l.end(), l[i]+l[j]) - l.begin();
    ans += k - j - 1;
  }
  cout << ans << endl;
  return 0;
}
