#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  ll A;
  double B;
  cin >> A >> B;
  ll ans = A * int(B * 100 + 0.1) / 100;
  cout << ans << endl;

  return 0;
}
