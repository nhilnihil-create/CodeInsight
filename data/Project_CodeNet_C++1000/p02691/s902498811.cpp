#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  map<int,ll> m, p;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    m[i-x] += 1;
    p[x+i] += 1;
  }
  ll ans = 0;
  for (auto r : p) {
    ans += r.second*m[r.first];
  }
  cout << ans << endl;
}