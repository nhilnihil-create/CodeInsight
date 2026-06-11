#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // 数字ごとに登場する index を管理する
  //
  // 例 S = 123123の場合
  // 1: 0, 3
  // 2: 1, 4
  // 3: 2, 5
  //
  vector<vector<int>> v(10, vector<int>(0));
  for (int i = 0; i < n; i++) {
    int a = s.at(i) - '0';
    v.at(a).push_back(i);
  }

  int ans = 0;
  // 000〜999 について、貪欲法で探索する
  for (int i = 0; i < 1000; i++) {
    string t = to_string(i);
    int digit = 3 - (int)t.size();
    for (int i = 0; i < digit; i++) {
      t = '0' + t;
    }

    // 3文字の数を、数字として取得
    int x = t.at(0) - '0';
    int y = t.at(1) - '0';
    int z = t.at(2) - '0';
    // index に存在しない場合はスキップ
    if (v.at(x).size() == 0) { continue; }
    if (v.at(y).size() == 0) { continue; }
    if (v.at(z).size() == 0) { continue; }

    // 1文字目の数字を index の開始位置となる
    int index = v.at(x).at(0);
    auto itr_y = upper_bound(v.at(y).begin(), v.at(y).end(), index);
    // 2文字目が見つからなかった場合
    if (itr_y == v.at(y).end()) { continue; }

    auto itr_z = upper_bound(v.at(z).begin(), v.at(z).end(), *itr_y);
    // 3文字目が見つからなかった場合
    if (itr_z == v.at(z).end()) { continue; }

    // 3文字とも見つかった場合はインクリメント
    ans++;
  }

  cout << ans << endl;
  return 0;
}
