#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  unordered_map<ll, ll> lum{}, rum{};
  REP(i, N) {
    lum[A[i] + i + 1]++;
    rum[-A[i] + i + 1]++;
  }
  ll ans = 0;
  for (auto s : lum) {
    ans += s.second*rum[s.first];
  }
  cout << ans << endl;
}