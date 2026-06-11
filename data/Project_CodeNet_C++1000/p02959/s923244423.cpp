#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N+1);
  vector<long long> B(N+1);
  rep(i, N+1){
    cin >> A[i];
  }
  rep(i, N){
    cin >> B[i];
  }
  // ここから本題
  // ansは倒したモンスターの数
  // yoryokuは勇者が次の街で余分に倒せるモンスターの数（余力）
  long long ans=0, yoryoku, toubatu, gamusyara;
  // 最初は例外処理
  toubatu = min(A[0], B[0]);
  ans += toubatu;
  yoryoku = B[0] - toubatu;
  // 最初と最後を除いたN-1回同じ処理をする
  rep(i, N-1){
    // 討伐するモンスター
    gamusyara = min(A[i+1], yoryoku);
    ans += gamusyara;
    A[i+1] -= gamusyara;
    toubatu = min(A[i+1], B[i+1]);
    ans += toubatu;
    // 毎回余力を更新していく
    yoryoku = B[i+1] - toubatu;
  }
  // 最後も例外処理
  gamusyara = min(A[N], yoryoku);
  ans += gamusyara;
  cout << ans << endl;
}