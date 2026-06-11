#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, Q;
vector<int> a, b, c, d;

int score(vector<int> A) {
    int res = 0;
    rep(i, Q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

int main(){
    // AとBはインデックスを表すので0インデックスに揃えておく
    // CとDはスコアなので関係ない
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    rep(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
  // next_permutationするためのvector
  // 辞書順で生成しておく必要があるため最初のM-1個を0に初期化する
  // vector自体は1で初期化しておいて後から最初のM-1個を0に初期化する
  // ボールが0で仕切り棒が1を表す
  vector<int> X(N+M-1, 1);
  rep(i, M-1) X[i] = 0;

  // 最終的なアウトプットを管理する変数
  int ans = 0;
  // next_permutationのdo部分
  do{
    // A_iは最小でも1
    int cnt = 1;
    // next_permutationによって生成されたAを管理するvector
    vector<int> Y;
    // next_permutationされたXをYに対応させる
    // 仕切り棒が出てきたらYにそれまでのボールの個数を追加する
    rep(i, X.size()){
      if (X[i]==1) Y.push_back(cnt);
      else cnt++;
    }

    // 問題文の条件を記述する
    ans = max(ans, score(Y));
  }

  // next_permutationのwhile部分
  while (next_permutation(X.begin(), X.end()));

  // 解答出力
  cout << ans << endl;
}