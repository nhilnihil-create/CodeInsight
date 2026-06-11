#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  ll x;
  cin >> x;
  ll ans = 0;
  ll yen = 100;
  while(1){
    if(yen >= x) break;
    yen += yen/100;
    ans++;
  }
  cout << ans << endl;
}