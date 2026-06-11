#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll h,a;
  cin >> h >> a;
  
  ll count = 0;
  rep(i, 100000){
    h -= a;
    count++;
    if(h <= 0)
      break;
  }
  cout << count << endl;
}