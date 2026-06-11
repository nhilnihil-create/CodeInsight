#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x){

  ll ans = 1;
  
  for(ll i=1; i*i<=x; i++){
    if(x%i==0){
      ans = max(ans, i);
    }
  }

  return ans;
}



int main(){
  ll N;
  cin >> N;  
  
  int res = calc(N);
  
  cout << (res-1)+(N/res)-1 << endl;
  
  
  return 0;
}