#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,k;
  cin >> n >> k;
  ll cnt=0;
  rep(i,n){
    int h;
    cin >> h;
    if(h >= k){
      cnt++;
    }
  }
  
  cout << cnt << endl;
  
  return(0);
}