#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &e : A) cin >> e;
  vector<int> sieve(1000001);
  for (int i = 0; i < 1000001; i++) sieve[i] = i;
  for (int i = 2; i < 1000; i++) {
    if (sieve[i] != i) continue;
    for (int j = 2; i*j < 1000001; j++) sieve[i*j] = i;
  }
  set<int> div_a;
  int q = gcd(A[0],A[1]);
  int s = 0;
  for (int i = 2; i < N; i++) q = gcd(q,A[i]);
  if (q > 1) cout << "not coprime" << endl;
  else {
    for (auto e : A) {
      set<int> div;
      while (e > 1) {
        div.insert(sieve[e]);
        div_a.insert(sieve[e]);
        e /= sieve[e];
      }
      int a = div.size();
      s += a;
    }
    int t = div_a.size();
    cout << (s == t ? "pairwise coprime" : "setwise coprime") << endl; 
  }
}