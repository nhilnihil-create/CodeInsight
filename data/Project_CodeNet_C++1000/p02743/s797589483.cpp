#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ld eps = 1.0e-14;

int main() {
  ld a,b,c;
  cin >> a >> b >> c;
  if(sqrt(a) + sqrt(b) + eps < sqrt(c)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return(0);
}