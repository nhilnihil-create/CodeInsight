#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, K;
  cin >> N >> K;
  vector <int> h(N);
  rep(i,N) cin >> h.at(i);

  int ans = 0;
  rep(i,N){
    if (h.at(i) >= K) ans++;
  }
  cout << ans << endl;
}
