#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  ll L, R;
  cin >> L >> R;
  
  vector<ll> x;
  
  if(R-L>2500){
    cout << 0 << endl;
  }else{
    ll res = 2018;
    for(ll i=L; i<R; i++){
      for(ll j=i+1; j<=R; j++){
        res = min(res, (i*j)%2019);
      
      }
    }
    cout << res << endl;
  }
  
  return 0;
}