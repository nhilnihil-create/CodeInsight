#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, D, ans=0;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  rep(i, N){
    rep(j, D){
      cin >> X[i][j];
    }
  }

  // ここからソルバー
  // とりあえず全ての組み合わせを試していく
  rep(i, N){
    repi(j, i+1, N){
      int length = 0;
      // 各要素ごとに二乗誤差を測る
      rep(k, D){
        int diff = abs(X[i][k] - X[j][k]);
        length += diff * diff;
      }
      // 平方数になっているかの判断
      // lengthが1のときに備えて範囲は0からlength+1まで
      bool flag = false;
      rep(l, length+1){
        // もし平方数であればflagをtrueに
        if (l*l==length){
          flag = true;
          break;
        }
      }
    // 平方数であればansをインクリメント
    if (flag) ans++;
    }
  }
  // 出力
  cout << ans << endl;
}