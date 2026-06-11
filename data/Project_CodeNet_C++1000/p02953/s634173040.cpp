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
  int mx = 0;
  rep(i,N){
    mx = max(mx, H[i]);
    if (mx == H[i]) continue;
    if (mx - 1 == H[i]) continue;
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
