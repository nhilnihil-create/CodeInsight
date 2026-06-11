#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, A, B, C, D = 0;
  cin >> N >> A >> B;
  C = N / (A + B);
  for (ll i = 0; i < C; i++) {D += A;}
  if (N % (A + B) < A) {D += N % (A + B);}
  else {D += A;}
  cout << D << endl;
}