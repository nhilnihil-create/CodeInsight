#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> F(N);
  rep(i, N) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  ll left = -1, right = 1e12;
  while (left+1 < right) {
    ll mid = (left + right) / 2;
    bool ok = [&]{
      ll sum = 0;
      rep(i, N) {
        sum += max(0ll, A[i] - mid/F[i]);
      }
      return sum <= K;
    }();
    if (ok) right = mid; else left = mid;
  }
  cout << right << '\n';
  return 0;
}