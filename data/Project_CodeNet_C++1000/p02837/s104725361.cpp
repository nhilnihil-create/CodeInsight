#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  // データを受け取る
  vector<vector<pair<int, int>>> vvp(n, vector<pair<int, int>>(0));
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vvp.at(i).resize(a);

    for (int j = 0; j < a; j++) {
      int x, y;
      cin >> x >> y;
      x--; // 0-indexed
      vvp.at(i).at(j) = make_pair(x, y);
    }
  }

  // 受け取ったデータの確認
#ifndef ONLINE_JUDGE
  for (int i = 0; i < n; i++) {
    cout << "i: " << i << endl;
    for (auto p : vvp.at(i)) {
      cout << "x,y: " << p.first << "," << p.second << endl;
    }
  }
#endif

  // bit全探索する
  //
  // n=3の場合、1000 = 8 のため 0〜7 の8パターンになる
  // つまり 000〜111 が探索範囲となる
  // 0,1 の定義は以下とする
  //
  // * 0 = 不親切な人
  // * 1 = 正直者
  //
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int ok = true;

    for (int j = 0; j < n; j++) {
      // j桁目のフラグが立っている (=1) 場合、
      // j番目のユーザーを「正直者」と仮定し、証言を採用する
      //
      // 証言が bit 全探索のパターンと矛盾するかどうかを確認
      if (i & (1 << j)) {
        for (auto p : vvp.at(j)) {
          int x = p.first;
          int y = p.second;
          // ### 例
          // i = 3 の場合、2進数に変換すると 011 になる。
          // つまり、1人目・2人目が正直者であるパターン。
          //
          // (x, y) = (2, 1) の場合、0-indexed にすると (1, 1) となる
          //
          // (i >> x) = (011 >> 1) から、右シフトすると 001 となる。
          // フラグが立っているため、2人目の人は正直者であるパターン。
          //
          // XOR で探索するパターンと、証言に矛盾があるか確認。
          // 矛盾がある場合、(0,1) or (1,0) の組み合わせで結果 1 が返る
          if (((i >> x) ^ y) & 1) {
            // 矛盾が発生したら bool を false にする
            ok = false;
          }
        }
      }
    }

    if (ok) {
      ans = max(ans, __builtin_popcount(i));
    }
  }

  cout << ans << endl;
  return 0;
}
