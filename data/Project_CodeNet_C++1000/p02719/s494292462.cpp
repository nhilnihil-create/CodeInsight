#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,k;
  cin >> n >> k;
  
  n %= k;
  
  if(n * 2 > k)
    n = k - n;
  
  cout << n << endl;
}