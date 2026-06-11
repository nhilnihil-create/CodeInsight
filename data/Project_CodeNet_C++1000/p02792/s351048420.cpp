#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    // i以下の数とiの組み合わせで条件を満たすものを数える
    int m = to_string(i).size();
    int first = i / pow(10, m - 1);
    int last = i % 10;
    if (last == 0) continue;
    if (i < 10) {
      ans++;
    } else if (first == last) {
      // 桁が同じもの
      int add = (i - first * pow(10, m - 1)) / 10;
      ans += 2 * add;
      // i以外
      ans += 1;  // i自身との組み合わせ
      // 桁が違うもの
      for (int l = m - 1; l >= 1; l--) {  // l:桁数
        if (l <= 2) {
          ans += 2;
        } else {
          ans += 2 * pow(10, (l - 2));
        }
      }
    } else if (first > last) {
      // 桁数が同じものも含む
      for (int l = m; l >= 1; l--) {  // l:桁数
        if (l == 1) continue;
        if (l == 2) {
          ans += 2;
        } else {
          ans += 2 * pow(10, (l - 2));
        }
      }
    } else {
      for (int l = m - 1; l >= 1; l--) {  // l:桁数
        if (l == 1) continue;
        if (l == 2) {
          ans += 2;
        } else {
          ans += 2 * pow(10, (l - 2));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}