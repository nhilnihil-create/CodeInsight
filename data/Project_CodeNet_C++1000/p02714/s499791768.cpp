#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  string S;
  cin >> N >> S;
  ll R = 0;
  ll G = 0;
  ll B = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      R++;
    } else if (S[i] == 'G') {
      G++;
    } else {
      B++;
    }
  }
  ll ans = R*G*B;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j+i+i < N; j++) {
      if (S[j] != S[j+i] && S[j+i] != S[j+i+i] && S[j+i+i] != S[j]) {
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}