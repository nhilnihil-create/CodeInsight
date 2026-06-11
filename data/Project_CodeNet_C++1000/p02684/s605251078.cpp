#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n,K;
  cin >> n >> K;
  vector<ll> A(n);
  for (auto& _a : A) {
    cin >> _a;
    --_a;
  }
  ll idx = 0;
  unordered_map<ll,ll> m;
  ll i = 0;
  while (i < K) {
    if (m.count(idx)) {
      ll cycle_len = i - m[idx];
      ll steps_remain = K - i;
      i += (steps_remain/cycle_len)*cycle_len;
      if (i==K) break;
    } else {
      m[idx] = i;
    }
    idx = A[idx];
    ++i;
  }
  cout << idx+1 << endl;
  

}
