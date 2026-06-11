#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll k,count = 0,sum = 0;
  cin >> k;
  
  for(ll i=0; i<10e8; i++){
    sum += k;
    for(;;){
      if(sum%10 == 7){
        sum/=10;
        count++;
      }else break;
    }
    if(sum == 0) break;
  }
  
  if(sum != 0)cout << -1 << endl;
  else cout << count << endl;
  
}