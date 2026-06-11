#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  if (n % 2 == 0){
    ll temp = n;
    ll tw = 0;
    while(temp >= 2){
      temp /= 2;
      tw += temp;
    }
    temp = n/2;
    ll fi = 0;
    while(temp >= 5){
      temp /= 5;
      fi += temp;
    }
    ans = min(tw, fi);
  }
  cout << ans << endl;
  
  return 0;
}