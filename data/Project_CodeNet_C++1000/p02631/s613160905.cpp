#include <bits/stdc++.h>


using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll res = 0;
  for(auto& x : a) {
    cin >> x;
    res ^= x;
  }
  for(auto x : a) {
    cout << (res ^ x) << " ";
  }
  cout << "\n";

    



  return 0;
}

