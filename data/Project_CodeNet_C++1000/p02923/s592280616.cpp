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
  vector <int> H(N);
  rep(i,N) cin >> H[i];
  int ans = 0;
  int cnt = 0;
  for (int i = 1; i < N; i++){
    if (H[i - 1] >= H[i]){
      cnt ++;
      ans = max(ans, cnt);
    }else{
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
