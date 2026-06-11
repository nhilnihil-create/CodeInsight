#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  ll N;
  cin >> N;
  
  vector<ll> H(N);
  for(ll i=0; i<N; i++) cin >> H[i];
  
  
  for(ll i=N-2; i>=0; --i){
    if(H[i]>H[i+1]){
      if((H[i]-H[i+1])>=2){
        cout << "No" << endl;
        return 0;
      }
      H[i] -= 1;
    }
  }
  
  
  cout << "Yes" << endl;
  
  return 0;
}