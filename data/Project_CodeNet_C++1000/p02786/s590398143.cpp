#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  ll h;
  cin >> h;
  ll cnt = 0;
  while(h != 0) {
    h = floor(h/2);
    cnt++;
  }
  ll ans = 0;
  rep(i,cnt) ans += pow(2,i);
  cout << ans << endl;
  return 0;
}