#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int K, N;
  cin >> K >> N;
  vector <int> A(N);
  rep(i,N){
    cin >> A[i];
  }
  int sa = 0;  //A_iとA_i+1の距離の差の最大値
  for (int i = 0; i < N - 1; i++){
    sa = max(sa, (A[i + 1] - A[i]));
  }
  sa = max(sa, (A[0] + K - A[N - 1]));
  cout << K - sa << endl;
  return 0;
}
