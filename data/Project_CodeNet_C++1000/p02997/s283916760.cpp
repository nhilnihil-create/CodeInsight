#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  int max_p = (N-1) * (N-2) / 2;  // 距離 2 の組数の上限
  if (max_p < K) { cout << -1 << endl; return 0; }
  vector<pair<int, int>> ans;
  // うにを作ると距離 2 の組は max_p 組できる
  for (int i = 0; i < N-1; i++) {
    ans.push_back(make_pair(i+1, N));
  }
  // うにの先端の頂点同士を結ぶと、距離 2 の組が 1 つ減る
  int add = max_p - K;
  vector<pair<int, int>> E;  // 加える辺の候補を挙げておく
  for (int i = 0; i < N-2; i++) {
    for (int j = i+1; j < N-1; j++) {
      E.push_back(make_pair(i+1, j+1));
    }
  }
  for (int i = 0; i < add; i++) ans.push_back(E.at(i));
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans.at(i).first << " " << ans.at(i).second << endl;
  }
}