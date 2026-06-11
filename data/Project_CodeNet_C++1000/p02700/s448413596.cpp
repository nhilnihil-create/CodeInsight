#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  
  ll x = (a + d - 1) / d, y = (b + c - 1) / b;
  
  if(x >= y) cout << "Yes" << endl;
  else cout << "No" << endl;
} 