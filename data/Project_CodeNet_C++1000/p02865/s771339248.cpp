#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  ll ans ;
  if(n%2==0) ans = n / 2 -1;
  else ans = (n-1) /2;
  cout << ans << endl;
}