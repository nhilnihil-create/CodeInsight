#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  ll N, D;
  cin >> N >> D;
  vector <ll> x(N);
  vector <ll> y(N);
  rep(i,N) cin >> x[i] >> y[i];

  int ans = 0;
  rep(i,N){
    if (x[i] * x[i] + y[i] * y[i] <= D * D){
      ans ++;
    }
  }

  cout << ans << endl;

}
