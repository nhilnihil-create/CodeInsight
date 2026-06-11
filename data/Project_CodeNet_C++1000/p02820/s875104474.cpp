#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  int R,S,P;
  cin >> R >> S >> P;
  string T;
  cin >> T;
  vector<char> modK[K];
  for (int i = 0; i < N; i++) {
    modK[i % K].push_back(T[i]);
  }
  ll ans = 0;
  for (int i = 0; i < K; i++) {
    char bc = modK[i][0];
    int streak = 1;
    for (int j = 1; j < (int)modK[i].size(); j++) {
      if (bc == modK[i][j]) {
        streak++;
      } else {
        ll r = ((streak+1) / 2);
        if (bc == 'r') {
          r *= P;
        } else if (bc == 's') {
          r *= R;
        } else {
          r *= S;
        }
        ans += r;
        streak = 1;
        bc = modK[i][j];
      }
    }
    ll r = ((streak+1) / 2);
    if (bc == 'r') {
      r *= P;
    } else if (bc == 's') {
      r *= R;
    } else {
      r *= S;
    }
    ans += r;
  }
  cout << ans << endl;
  return 0;
}