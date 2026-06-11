#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N, a, b, c, ans;
int X[30];

int main(){
  cin >> N;
  // とりあえずXに入れる
  rep(i, N){
    cin >> X[i];
  }
  // 左から貪欲に調べていく
  // 繰り返し回数はN-3+1回
  rep(i, N-3+1){
    // 調べる3つの数字を格納する配列
    int Y[3];
    // 格納していく
    rep(j, 3){
      Y[j] = X[i+j];
    }
    // ソートする
    sort(Y, Y+3);
    // 2番目が変わらなければ条件に一致する
    if (Y[1]==X[i+1]) ans++;
  }
  // 出力
  cout << ans << endl;
}