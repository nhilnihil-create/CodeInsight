#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(void){
  ll a, b, k;
  cin >> a >> b >> k;
  if(k > a){ 
    b -= k-a;
    a = 0;
    cout << a << " ";
    if(b < 0) cout << 0 << endl;
    else cout << b << endl;
  }
  else{
    a -= k;
    cout << a << " " << b << endl;
  }
  return 0;
}