#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, k) {
    int d;
    cin >> d;
    rep(j, d) {
      int t;
      cin >> t;
      a[t - 1]++;
    }
  }

  int ans = 0;
  rep(i, n) {
    if(a[i] == 0) {
      ans++;
    }
  }
  cout << ans;
}
