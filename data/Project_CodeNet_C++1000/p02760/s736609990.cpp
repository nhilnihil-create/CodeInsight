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
  vector<vector<int>> v(3, vector<int>(3)), u(3, vector<int>(3));
  rep(i,3) rep(j,3) cin >> v[i][j];
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i,n) cin >> b[i];
  rep(i,n) {
    int t = b[i];
    rep(j,3) rep(k,3) if (v[j][k] == t) u[j][k] = 1;
  }
  bool is = false;
  rep(i,3) {
    if (u[i][0] && u[i][1] && u[i][2]) is = is || true;
  }
  rep(i,3) {
    if (u[0][i] && u[1][i] && u[2][i]) is = is || true;
  }
  if (u[0][0] && u[1][1] && u[2][2]) is = is || true;
  if (u[0][2] && u[1][1] && u[2][0]) is = is || true;
  cout << (is? "Yes": "No") << endl;

}

int main() {
  solve();
  return 0;
}