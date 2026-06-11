#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <ll> a(N), b(N), x(N), y(N);
  rep(i,N){
    cin >> a[i] >> b[i];
    x[i] = a[i] + b[i];
    y[i] = a[i] - b[i];
  }
  ll x_ = *max_element(all(x)) - *min_element(all(x));
  ll y_ = *max_element(all(y)) - *min_element(all(y));
  ll ans = max(x_, y_);
  cout << ans << endl;

  // 誤り
  // vector <ll> sum(N);
  // rep(i,N) sum[i] = p[i].first + p[i].second;
  // // cのmaxとminが同じ場合
  // if (*max_element(all(sum)) == *min_element(all(sum))){
  //   sort(all(p));
  //   cout << (p[N-1].first - p[0].first) * 2 << endl;
  //   return 0;
  // }else{
  //   int mn = min_element(all(sum)) - sum.begin();
  //   int mx = max_element(all(sum)) - sum.begin();
  //   ll ans = abs(p[mx].first - p[mn].first) + abs(p[mx].second - p[mn].second);
  //   cout << ans << endl;
  // }
  return 0;
}
