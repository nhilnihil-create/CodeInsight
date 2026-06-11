#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A[200];

int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N) cin >> A[i];

  // とりあえず投票総数を計算
  int sums = 0;
  rep(i, N) sums += A[i];

  // 選べない商品の投票数の境目
  double thres = (double) sums / (4 * M);

  // 全探索
  int ans = 0;
  rep(i, N){
    if (A[i] >= thres) ans++;
  }

  // もし選べる商品がM個以上あればOK
  if (ans >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
}
