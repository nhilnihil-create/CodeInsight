#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ld eps = 1.0e-18;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  //cout << sqrtl((ld)a) << endl;
  if(c-a-b > 0 && 4*a*b < (c-a-b)*(c-a-b)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return(0);
}