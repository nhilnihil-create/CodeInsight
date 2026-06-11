#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int Y, X;
  vector<vector<int>> s(H, vector<int>(W, 0));
  REP(y, H) {
    REP(x, W) {
      if (y < B && x < A || y >= B && x >= A) {
        s[y][x] = 1;
      }
    }
  }
  REP(y, H) {
    REP(x, W) {
      cout << s[y][x];
    }
    cout << endl;
  }
  return 0;
}