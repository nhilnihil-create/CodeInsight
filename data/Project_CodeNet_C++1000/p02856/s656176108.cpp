#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll M;
  cin >> M;
  ll d[M],c[M];
  ll csum = 0;
  ll dsum = 0;
  for (int i = 0; i < M; i++) {
    cin >> d[i] >> c[i];
    csum += c[i];
    dsum += (d[i] * c[i]);
  }
  ll ans = (csum - 1) + ((dsum - 1) / 9);
  cout << ans << endl;
  return 0;
}