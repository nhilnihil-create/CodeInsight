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
  string S;
  cin >> S;
  int ans = 1;
  for (int i = 1; i < N; i++){
    if (S[i] != S[i - 1]) ans ++;
  }
  cout << ans << endl;
  return 0;
}
