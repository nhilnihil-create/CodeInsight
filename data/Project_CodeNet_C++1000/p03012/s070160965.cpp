#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> rui(n);
    rep(i,n) {
      int w;
      cin >> w;
      if (i == 0) rui[i] = w;
      else rui[i] = rui[i-1] + w;
    }
    int ans = 1001001001;
    for (int i = 0; i < n-1; i++) {
      int s1 = rui[i];
      int s2 = rui[n-1]-s1;
      ans = min(ans, abs(s1-s2));
    }
    cout << ans << endl;
    return 0;
}