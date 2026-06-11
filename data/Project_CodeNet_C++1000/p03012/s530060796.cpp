#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int W[200];
// 累積和を保存していく配列
int S[200];
int N = 0;
// 差の初期値は100よりも大きい値にしておく
int gap = 200;

int main(){
  // 入力を格納していくフェーズ
  cin >> N;
  rep(i, N){
    cin >> W[i+1];
  }
  rep(i, N){
    S[i+1] += S[i] + W[i+1];
  }

  // ここからソルバー
  // 累積和から左側と右側の和を求める
  rep(i, N-1){
    int left = S[i+1];
    int right = S[N] - S[i+1];
  // 絶対値の差を計算
    gap = min(gap, abs(left-right));
  }
  cout << gap << endl;
}