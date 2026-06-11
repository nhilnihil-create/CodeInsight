#include <iostream>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  ll m;
  cin >> m;
  ll d, c;
  ll ans = -1;
  ll sum = 0;
  rep(i, m){
    cin >> d >> c;
    ans += c;
    sum += d * c;
  }
  ans += (sum-1) / 9;
  cout << ans << endl;
  
  return 0;
}