#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) {
    ll B;
    cin >> B;
    A[i] = B * 1000000 + i;
  }
  sort(A.begin(), A.end());
  ll x = A[N - 1] % 1000000;
  ll ans = (A[N - 1] - x) / 1000000;
  for(int i = 0; i < N; i++) {
    if(i != x) {
      cout << ans << endl;
    }
    else {
      ll y = A[N - 2] % 1000000;
      cout << (A[N - 2] - y) / 1000000 << endl;
    }
  }
}