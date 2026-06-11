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
  vector <int> P(N);
  rep(i,N) cin >> P[i];
  int ans = 0;
  int curMin = 1e9;  //今までのmin
  rep(i,N){
    curMin = min(curMin, P[i]);
    if (P[i] == curMin) ans ++;
  }
  cout << ans << endl;
  return 0;
}
