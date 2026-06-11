#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, K;
  cin >> N >> K;

  int ans = 0;
  while (N > 0){
    N /= K;
    ans ++;
  }
  cout << ans << endl;
}
