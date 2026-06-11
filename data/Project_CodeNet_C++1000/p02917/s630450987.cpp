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
  vector <int> B(N - 1);
  rep(i,N - 1) cin >> B[i];
  vector <int> A(N);
  A[0] = B[0];
  for (int i = 1; i <= N - 2; i++){
    A[i] = min(B[i], B[i - 1]);
  }
  A[N - 1] = B[N - 2];
  int ans = accumulate(A.begin(), A.end(), 0);
  cout << ans << endl;
  return 0;
}
