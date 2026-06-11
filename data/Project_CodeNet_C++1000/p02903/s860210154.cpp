#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  vector<string> S(H, "");
  REP(i, H) REP(j, W) { S[i].push_back('0'); }
  REP(i, H) REP(j, W) {
    if (i < H - B) {
      if (j < W - A) {
        S[i][j] = '1';
      }
    } else {
      if (j >= W - A) {
        S[i][j] = '1';
      }
    }
  }
  REP(i, H) cout << S[i] << endl;
}