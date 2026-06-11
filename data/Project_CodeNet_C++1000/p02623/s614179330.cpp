//しゃくとり法（尺取り法）

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M, K;
  cin >> N >> M >> K;
  vector <int> A(N);
  vector <int> B(M);
  rep(i,N) cin >> A[i];
  rep(i,M) cin >> B[i];

  ll t = 0;
  //Bを全部読む時間 この下のwhile内でK以下にする
  rep(i,M) t += B[i];

  int j = M;
  int ans = 0;
  //iはAを読む冊数
  rep(i,N + 1){
    while (j > 0 && t > K){
      j--;
      t -= B[j];  //0-indexedでj番目の本を読むのを諦める
    }
    if (t > K) break;  //j == 0のときのため
    ans = max(ans, i + j);
    if (i == N) break;
    t += A[i];
  }
  cout << ans << endl;
  return 0;
}
