#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (auto& _a : A) cin >> _a;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] == j+1) {
      ++j;
    }
  }
  int n_remain = j;
  int n_break = n - j;
  if (n_break == n) {
    cout << -1 << endl;
  } else {
    cout << n_break << endl;
  }

}
