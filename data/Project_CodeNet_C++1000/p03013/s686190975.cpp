#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N=0, M=0;
// 割る数の定義
long long MOD = pow(10, 9)+7;

int main(){
  cin >> N >> M;
  // 階段が壊れているかどうかのflag
  vector<bool> flag(N+1, true);
  // DPテーブル。漸化式の計算結果を保存しておく用
  vector<long long> DP(N+1, 0);
  rep(i, M){
    int a = 0;
    cin >> a;
    flag[a] = false;
  }
  // 今いる場所は1通りと考えることで辻褄が合う
  DP[0] = 1;
  // 1段目が壊れていれば0のまま，壊れていなければ1で初期化する
  if (flag[1]==true) DP[1]=1;
  // MODで割ったあまりを格納していけば良い
  rep(i, N-1){
    if (flag[i+2]==true) DP[i+2] = (DP[i+1]+DP[i]) % MOD;
  }
    // DPテーブルは0段目が0インデックスなのでN段目はNインデックス
    cout << DP[N] << endl;
}