#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int R, S, P;
  cin >> R >> S >> P;
  string t;
  cin >> t;
  rep(i,n-k)
    if (t[i] == t[i+k]) t[i+k] = 'n';
  int ans = 0;
  rep(i,n) {
    if (t[i] == 'r')
      ans += P;
    if (t[i] == 's')
      ans += R;
    if (t[i] == 'p')
      ans += S;
  }
  cout << ans << endl;
}