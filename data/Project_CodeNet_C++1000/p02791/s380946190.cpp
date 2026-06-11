#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmin(T& a,T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  int t = 10000000;
  int ans = 0;
  rep(i,0,n) {
    int p;
    cin >> p;
    if (chmin(t,p)) ans++;
  }
  cout << ans << endl;
  return 0;
}
