#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 全探索
  int N, X, Y;
  cin >> N >> X >> Y;
  X--; Y--;
  vector<int> cnt(N);
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      int d = min(j-i, abs(i-X) + abs(j-Y) + 1);
      cnt[d]++;
    }
  }
  for (int i = 1; i < N; i++) {
    cout << cnt[i] << '\n';
  }
  return 0;
}