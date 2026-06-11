#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  long long N, Q, R;
  long long ans = pow(10, 12) + 1;
  cin >> N;
  rep(i, sqrt(N)+1){
    Q = N / (i+1);
    R = N % (i+1);
    if (R == 0) ans = min(ans, i + Q - 1);
  }
  cout << ans << endl;
}
