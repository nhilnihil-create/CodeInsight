#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e9;

int main() {
  // 全探索
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, N) cin >> X[i];
  int ans = INF;
  for (int i = 1; i < 101; i++) {
    int temp = 0;
    for (int x : X) {
      temp += pow((i - x), 2);
    }
    if (temp < ans) ans = temp;    
  }
  cout << ans << '\n';
  return 0;
}