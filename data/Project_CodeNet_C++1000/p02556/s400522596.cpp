#include <bits/stdc++.h>
using namespace std;

#define ll long long

void chmax(ll& a, ll b) {
  if (a < b) a = b;
}

void chmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  int N;
  cin >> N;
  
  
  ll z_max = -10000000000, z_min = 10000000000;
  ll w_max = -10000000000, w_min = 10000000000; 
  for (int i = 0; i < N; i++) {
    ll x,y;
    cin >> x >> y;
    
    ll z = x + y, w = x - y;
    
    chmax(z_max, z);
    chmin(z_min, z);
    chmax(w_max, w);
    chmin(w_min, w);
  }
  
  cout << max(z_max-z_min, w_max- w_min) << endl;
 
}