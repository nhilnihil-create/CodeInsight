#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<pair<int,int>> X;
  rep0(i, N) {
    int x, l; cin >> x >> l;
    X.push_back(make_pair(x+l, x-l));
  }
  
  sort(all(X));
  int ans = 1;

  int M = X[0].first;
  rep1(i, N) {
    if(X[i].second >= M) {
      ans++;
      M = X[i].first;
    }
  }
  cout << ans << endl;

}