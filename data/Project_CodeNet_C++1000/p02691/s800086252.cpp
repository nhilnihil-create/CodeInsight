#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  map<ll, ll> L, R;
  for (int i=0; i<N; i++) {
    if (L.count(i+A[i])) L[i+A[i]]++;
    else L[i+A[i]] = 1;
  }
  for (int i=0; i<N; i++) {
    if (R.count(i-A[i])) R[i-A[i]]++;
    else R[i-A[i]] = 1;
  }
  ll res = 0;
  for (auto p: L) {
    auto key = p.first;
    auto value = p.second;
    res += value*R[key];
  }
  cout << res << endl;
  return 0;
}