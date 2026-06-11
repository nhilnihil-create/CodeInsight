#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int X, N;
  cin >> X >> N;
  vector <int> d(102);  //現れたら1
  rep(i,N){
    int p;
    cin >> p;
    d[p] = 1;
  }
  P ans(999, -1);  //差分と位置のペア
  for (int i = 0; i <= 101; i++){
    if (d[i] == 1) continue;
    int dif = abs(X-i);
    ans = min(ans, P(dif, i));
  }
  cout << ans.second << endl;

  return 0;
}
