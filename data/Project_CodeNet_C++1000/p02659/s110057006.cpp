#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll a,c; double b;
  cin >>a >>b;
  c = b*100+0.5;
  ll ans = a*c/100;
  cout << ans << endl;
  return 0;
}