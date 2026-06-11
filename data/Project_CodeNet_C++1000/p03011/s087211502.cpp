#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i < (int)(n+1); i++)
#define N_MAX 110
#define K_MAX 100010

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;

  int res = P + Q + R - max(max(P, Q), R);

  cout << res << endl; 
  return 0;
}