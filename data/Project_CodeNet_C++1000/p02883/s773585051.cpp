#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> F(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  ll l = -1, r = 1e12;
  while(l+1 < r) {
    ll c = (l+r)/2;
    ll sum = 0;
    rep(i,N) {
      sum += max(0ll, A[i] - c/F[i]);
    }
    if (sum <= K) r = c;
    else l = c;
  }
  cout << r << endl;
}