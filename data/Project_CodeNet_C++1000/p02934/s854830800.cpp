#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> A(N);
  rep(i,N) cin >> A[i];

  double ans = 0.0;  //答えの分母
  rep(i,N){
    ans += 1.0 / A[i];
  }
  ans = 1.0 / ans;
  cout << setprecision(10) << ans << endl;
}
