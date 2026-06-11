#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll MOD = 1000000007;
  ll N, k;
  cin >> N >> k;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  ll f = 0;
  for (ll i = N-2; i >= 0; i--) {
    for (ll j = N-1; j >= i+1; j--) {
      if (A[i] > A[j]) f = (f+1)%MOD;
    }
  }
  ll r = 0;
  for (ll i = 1; i < N; i++) {
    for (ll j = 0; j < i; j++) {
      if (A[j] < A[i]) r = (r+1)%MOD;
    }
  }
  
  ll d = f+r;
  ll n = (k*(k-1)/2)%MOD;
  cout << ((k*f%MOD)+(n*d%MOD))%MOD << endl;
}