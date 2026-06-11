#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> A(N + 1);
  vector <int> B(N);
  rep(i,N + 1) cin >> A[i];
  rep(i,N) cin >> B[i];

  ll ans = 0;
  rep(i,N){
    //A_iへの攻撃
    ans += min(A[i], B[i]);
    B[i] -= min(A[i], B[i]);
    //A_i+1への攻撃
    ans += min(A[i + 1], B[i]);
    A[i + 1] -= min(A[i + 1], B[i]);
    //B[i] -= min(A[i + 1], B[i]);
  }
  cout << ans << endl;
  return 0;
}
