#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
const ll mod = pow(10, 9) + 7;  

ll modpow(ll n, ll k) {
  ll value = 1;
  for(ll i = 0; i < k; i++) {
    value = value * (n % mod) % mod; 
  }
  return value;
}
 
int main() {
  ll N, ans;
  cin >> N;
  ans = (modpow(10, N) - modpow(9, N)) % mod;
  ans = (ans - modpow(9, N)) % mod;
  ans = (ans + modpow(8, N)) % mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;
}