#include <bits/stdc++.h>
using namespace std;

const bool DEBUG = false;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int n2 = 1 << n;  // シフト演算子で2^nを作る
  vector<int> a(n2);
  for (size_t i = 0; i < n2; i++) cin >> a[i];
  sort(a.begin(), a.end());

  vector<int> s;  // 今の頂点集合．世代ごとに増えていく
  s.push_back(a.back());  // sの初期化．a.back()で末尾参照を取得 (最大値)
  a.back() = -1;  // 使用した要素は-1にすることにする．pop_back()で消さない
  for (size_t i = 0; i < n; i++) {  // n世代繰り返す
    vector<int> p = s;              // pに1世代前のデータをコピー
    sort(p.begin(), p.end());
    int ai = n2 - 1;
    while (p.size() > 0 && ai >= 0) {
      if (a[ai] == -1) {
        // すでに使用済みなら無視する
        --ai;
        continue;
      }
      if (a[ai] < p.back()) {
        // もしa[ai]がpの最大値よりも小さい (生成可能)なら
        s.push_back(a[ai]);  // 次世代にa[ai]を追加
        p.pop_back();        // 1世代前のpから候補を外す
        a[ai] = -1;          // a[ai]を使用済みに
      }
      --ai;
    }
    if (p.size() > 0) {
      // もし親として消化できてないノードがあるなら失敗
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
