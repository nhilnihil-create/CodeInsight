#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  string S;
  cin >> S;

  int ans = 0;
  for (int i = 0; i < N - 2; i++) {
    if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') ans++;
  }
  cout << ans << endl;
}