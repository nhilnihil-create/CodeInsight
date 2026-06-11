#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N = 0;
  ll D = 0;
  cin >> N >> D;
  D *= D;
  vector<ll> X(N);
  vector<ll> Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    X.at(i) *= X.at(i);
    Y.at(i) *= Y.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (D >= X.at(i) + Y.at(i)) ans++;
  }
  cout << ans << endl;
}