#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  ll A, B = 0;
  string S;
  cin >> A >> S;

  B += (int)(S[0] - '0') * 100 + (int)(S[2] - '0') * 10 + (int)(S[3] - '0');
  ll ans = A * B;
  ans /= 100;

  cout << ans << endl;
}