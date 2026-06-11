#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  ll T = A + B;
  if(A == 0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = A * ll(N/T);
  ll r = N % T;
  ans += min(A,r);
  cout << ans << endl;
  return 0;
}