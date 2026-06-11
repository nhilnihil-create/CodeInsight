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
  vector <int> X(N);
  rep(i,N) cin >> X[i];
  int ans = inf;  //体力の総和の最小値
  for (int i = 1; i <= 100; i++){
    int sum = 0;
    rep(j,N) sum += (X[j] - i) * (X[j] - i);
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
