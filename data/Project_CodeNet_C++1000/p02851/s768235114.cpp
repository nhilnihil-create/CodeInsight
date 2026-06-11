#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  ll K;
  cin >> K;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  ll ans = 0;
  map<ll,ll> mp;
  ll R[N+1];
  R[0] = 0;
  for (int i = 0; i < N; i++) {
    R[i+1] = R[i] + A[i];
  }
  ll res[N+1];
  for (int i = 0; i <= N; i++) {
    res[i] = (R[i] - i) % K;
  }
  for (int i = 0; i < min(N+1,K); i++) {
    mp[res[i]]++;
  }
  for (auto p : mp) {
    if (p.second > 0) {
      ans += ((p.second - 1) * p.second) / 2;
    }
  }
  
  for (int i = 0; i < N - K + 1; i++) {
    mp[res[i]]--;
    mp[res[i+K]]++;
    ans += mp[res[i+K]] - 1;
  }
  cout << ans << endl;
  return 0;
}