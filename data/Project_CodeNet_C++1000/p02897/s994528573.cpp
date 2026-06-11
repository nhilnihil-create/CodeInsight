#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  if(n % 2 == 0)
    cout << 0.5000000 << endl;
  else{
    double c = (double) n;
    cout << (int)(c/2+1) / c << endl;
  }
}