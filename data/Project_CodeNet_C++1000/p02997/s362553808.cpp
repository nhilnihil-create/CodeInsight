#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,K; cin >> N >> K;

  int mx = (N-1) * (N-2) / 2;
  if(K > mx) {
    cout << -1 << endl;
    return 0;
  }

  vector<P> ans;
  rep(i, N-1) {
    ans.push_back(P(i+1, N));
  }

  int add = mx - K;
  rep(i, N-1) {
    if(add == 0) break;
    for(int j = i+1; j < N-1; ++j) {
      if(add == 0) break;
      ans.push_back(P(i+1, j+1));
      --add;
    }
  }

  int anss = ans.size();
  cout << anss << endl;
  rep(i, anss) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
