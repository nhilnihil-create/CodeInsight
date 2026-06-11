#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int digit(int x) {
  // xの桁数を返す、0は一桁とする
  int res = 1;
  while (x >= 10) {
    res++;
    x /= 10;
  }
  return res;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<P> SC(M);
  rep(i, M) {
    cin >> SC[i].first >> SC[i].second;
  }
  // 0から順に探索
  for (int i = 0; i < 1000; i++) {
    if (N != digit(i)) continue;
    vector<int> num = {i % 10};
    int j = i;
    j /= 10;
    while (j) {
      num.push_back(j%10);
      j /= 10;
    }
    reverse(num.begin(), num.end());
    bool flag = true;
    rep(i, M) {
      if (num[SC[i].first-1] != SC[i].second)  flag = false;
    }
    if (flag) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}