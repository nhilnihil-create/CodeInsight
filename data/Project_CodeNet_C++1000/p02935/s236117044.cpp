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
  vector <int> v(N);
  rep(i,N) cin >> v[i];
  sort(all(v));
  double ans = v[0];
  for (int i = 1; i < N; i++){
    ans = (ans + v[i]) / 2.0;
  }
  cout << ans << endl;
  return 0;
}
