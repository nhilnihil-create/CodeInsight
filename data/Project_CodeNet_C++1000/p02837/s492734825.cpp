#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const long long INF = 1LL << 60;
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int N;
vector<vector<pair<int, int>>> A;

bool solve(int bit) {
  for (int i = 0; i < N; ++i) {
    if (!(bit & (1<<i))) continue;
    for (int j = 0; j < A[i].size(); ++j) {
      if (A[i][j].second == 0 && (bit & (1<<A[i][j].first))) return false;
      if (A[i][j].second == 1 && (!(bit & (1<<A[i][j].first)))) return false;
    }
  }
  return true;
}

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    A[i].resize(a);
    for (int j = 0; j < a; ++j) {
      int x, y;
      cin >> x >> y; x--;
      A[i][j].first = x;
      A[i][j].second = y;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1<<N); ++bit) {
    if (solve(bit)) {
      int cnt = 0;
      for (int i = 0; i < N; ++i) {
        if (bit & (1<<i)) cnt++;
      }
      ans = max(cnt, ans);
    }
  }
  cout << ans << endl;
}
