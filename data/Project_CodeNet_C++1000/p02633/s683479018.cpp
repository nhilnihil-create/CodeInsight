#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = ll(1e9 + 7);
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  int TT = 1;
  // cin >> TT;
  while (TT--) {
    ll x;
    cin >> x;
    ll v = lcm(360,x);
    cout << v/x << endl;
  }
}
