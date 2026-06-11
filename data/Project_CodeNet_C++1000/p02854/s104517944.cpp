#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for (ll &e : A) {
    cin >> e;
    sum += e;
  }
  
  ll s = 0;
  ll v = sum;
  for (int i = 0; i < N; i++) {
    ll delt;
    s += A[i];
    delt = max(s*2 - sum, sum - s*2);
    v = min(delt, v);
  }
  
  cout << v << endl;
}