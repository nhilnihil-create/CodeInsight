#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b,x,y;
  cin >> a >> b >> x >> y;
  bool tak = false
  
  rep(i, 1000000000000000000){
    x -= b;
    if(x <= 0){
      tak = true;
      break;
    }
    
    a -= y;
    if(a <= 0){
      break;
    }
  }
  
  if(tak)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
