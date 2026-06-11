#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll h;
  cin >> h;
  ll count = 1;
  ll bin = 1;
  
  rep(i, 1000000000000000000){
    h /= 2;
    bin *= 2;
    if(h == 0)
      break;
    else
      count += bin;
  }
  cout << count << endl;
}