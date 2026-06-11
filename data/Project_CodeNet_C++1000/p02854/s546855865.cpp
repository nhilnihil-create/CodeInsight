#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll sum = 0;
  vector<ll> A(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    A[i] = sum;
  }
  ll min_diff = sum;
  for (int i = 0; i < n; i++) {
    min_diff = min(min_diff, max(A[i], sum - A[i]) - min(A[i], sum - A[i]));
  }

  cout << min_diff << endl;

  return 0;
}