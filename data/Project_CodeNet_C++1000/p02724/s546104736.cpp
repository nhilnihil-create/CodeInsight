#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll x, y, z;
  cin >> x;
  
  y = x/500;
  z = (x % 500) / 5;
  
  cout << y * 1000 + z * 5 << endl;
}

