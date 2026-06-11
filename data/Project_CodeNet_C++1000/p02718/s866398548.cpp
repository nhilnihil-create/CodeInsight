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

  sort(A, A+N);
  reverse(A, A+N);

  // とりあえず投票総数を計算
  int sums = 0;
  rep(i, N) sums += A[i];

  // 選べない商品の投票数の境目
  // 整数型で宣言するとダメ
  double thres = (double) sums / (4 * M);

  // もし選べる商品がM個以上あればOK
  if (A[M-1] >= thres) cout << "Yes" << endl;
  else cout << "No" << endl;
}
