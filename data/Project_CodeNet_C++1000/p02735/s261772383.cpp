#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int H, W;
void dfs(vector<string> &A, vector<vector<ll>> &Ans, int num, P id) {
  if (id.first == H - 1 && id.second == W - 1) {
    if (A[id.first][id.second] == '#') num++;
  }
  if (Ans[id.first][id.second] <= num) return;
  Ans[id.first][id.second] = min(Ans[id.first][id.second], (ll)num);
  if (id.first < H - 1) {
    int ny = id.first + 1, nx = id.second;
    if (A[ny][nx] == '.' && A[id.first][id.second] == '#') {
      dfs(A, Ans, num + 1, P(ny, nx));
    } else {
      dfs(A, Ans, num, P(ny, nx));
    }
  }
  if (id.second < W - 1) {
    int ny = id.first, nx = id.second + 1;
    if (A[ny][nx] == '.' && A[id.first][id.second] == '#') {
      dfs(A, Ans, num + 1, P(ny, nx));
    } else {
      dfs(A, Ans, num, P(ny, nx));
    }
  }
}
int main() {
  cin >> H >> W;
  vector<string> A(110);
  REP(i, H) cin >> A[i];
  vector<vector<ll>> Ans(H + 2, vector<ll>(W + 2, 1e8));
  dfs(A, Ans, 0, P(0, 0));
  cout << Ans[H - 1][W - 1] << endl;
}