#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string t;
ll rp, sp, pp;
ll cal_score(char hand) {
  if (hand == 'r') return pp;
  if (hand == 's') return rp;
  if (hand == 'p') return sp;
  return 0;  // ここは通らない。
};

int main() {
  int n, k;
  cin >> n >> k >> rp >> sp >> pp >> t;

  ll score = 0;
  for (int i = 0; i < k; i++) {
    // MOD k で場合分け
    // 同じグループ内なら、「前回と同じ手は出せない」の条件になる。
    // プレイヤーはあいこ無し。勝つか負けるかする。

    bool lose_before = false;
    for (int j = i; j < n; j += k) {
      if (j == i) {
        // 初手は勝利
        score += cal_score(t[j]);
        lose_before = false;
        continue;
      }

      if (t[j - k] != t[j]) {
        // ロボットの手が前回と異なるとき、必ず勝てる。
        score += cal_score(t[j]);
        lose_before = false;
        continue;
      }

      if (t[j - k] == t[j] && lose_before) {
        // ロボットの手が前回と同じとき、前回負けてたら今回必ず勝てる。
        score += cal_score(t[j]);
        lose_before = false;
        continue;
      }

      lose_before = true;
    }
  }

  cout << score << endl;
  return 0;
}