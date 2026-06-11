#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  ll x,k,d;
  cin >> x >> k >> d;
  x = abs(x);
  if(x/d - k >= 0){
    cout << x-(k*d) << endl;
  }
  else{
    ll memo = x/d;
    k -= memo;
    x %= d;
    if(k%2 == 0){
      cout << x << endl;
    }
    else {
      cout << d-x << endl;
    }
  }
  
  return 0;
}
