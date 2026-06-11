#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M, X;
  cin >> N >> M >> X;
  vector <int> C(N);
  vector< vector<int> > A (12, vector<int>(12) );
  rep(i,N){
    cin >> C[i];
    rep(j,M){
      cin >> A[i][j];
    }
  }
  int ans = inf;
  rep(s, 1<<N){
    int cost = 0;
    vector <int> d(M);
    rep(i,N){
      if (s>>i&1){
        cost += C[i];
        rep(j,M) d[j] += A[i][j];

      }
    }
    bool ok = true;
    rep(j,M) if (d[j] < X) ok = false;
    if(ok) ans = min(ans, cost);
  }
  if (ans == inf) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
