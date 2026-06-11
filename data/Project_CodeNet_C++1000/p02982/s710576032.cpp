#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> v(n, vector<int>(d));
  rep(i,n) rep(j,d) cin >> v[i][j];

  int ans = 0;

  rep(i,n) {
    for (int j = i + 1; j < n; j++) {
      int naka = 0;
      rep(k, d) {
        naka += pow((v[i][k] - v[j][k]), 2);
      }
      for (int k = 1; k * k <= 16000; k++) {
        if (naka == k * k) {
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}