#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  ll n; cin>>n;
  ll zMAX,zMIN,wMAX,wMIN;
  rep(i,n){
    ll x,y; cin>>x>>y;
    if(i==0){
      zMAX = zMIN = x + y;
      wMAX = wMIN = x - y;
    }else{
      ll z = x+y, w = x-y;
      zMAX = max(zMAX,z);
      zMIN = min(zMIN,z);
      wMAX = max(wMAX,w);
      wMIN = min(wMIN,w);
    }
  }
  cout << max(zMAX-zMIN,wMAX-wMIN) << endl;
}