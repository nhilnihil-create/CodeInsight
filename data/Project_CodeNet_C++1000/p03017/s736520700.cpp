#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d;
  cin >> s;

  string tmp;

  // まずはBの移動経路を確認
  tmp = s.substr(b - 1, d - b + 1);
  if (tmp.find("##", 0) != std::string::npos) {
    cout << "No" << endl;;
    return 0;
  }

  // 次にAを移動させる
  tmp = s.substr(a - 1, c - a + 1);
  if (tmp.find("##", 0) != std::string::npos) {
    cout << "No" << endl;
    return 0;
  }

  if (c < d) {
    cout << "Yes" << endl;
    return 0;
  }

  // AがBを飛び越す必要があるとき
  // Bの初期位置の一つ手前からBの移動先の一つ先までの間に"..."があれば
  // Aは移動できる？
  tmp = s.substr(b - 2, d - b + 3);
  if (tmp.find("...", 0) == std::string::npos) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}