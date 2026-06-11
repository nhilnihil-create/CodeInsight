#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(void){
  ll a; double b;
  cin >> a >> b;
  ll B = b * 100 + 0.01;
  ll ans = a*B/100;
  cout << ans << endl;
  return 0;
}