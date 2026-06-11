#include <bits/stdc++.h>
#define rep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;

int main(void){
  int k;
  cin >> k;
  int ans = 0;
  rep(a,k) rep(b,k) rep(c,k){
    ans += gcd(a,gcd(b,c));
  }
  cout << ans << endl;
  return 0;
}