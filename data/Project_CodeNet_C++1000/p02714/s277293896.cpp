#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >> N;
  string M;
  cin >> M;
  ll ans;
  ll r=0,g=0,b=0;
  for(ll i=0;i<N;i++){
    
    if(M[i]=='R'){
      r++;
    }
    if(M[i]=='G'){
      g++;
    }
    if(M[i]=='B'){
      b++;
    }
    if(i==N-1){
      ans=r*g*b;
    }
  }

  for(ll i=0;i<N;i++){
    for(ll j=i+1;2*j-i<N;j++){
      if(M[j]==M[i]){
        continue;
      }
      else{
        if(M[2*j-i]!=M[j] && M[2*j-i]!=M[i]){
            ans--;
        }
      }
    }
  }
  cout << ans <<endl;
}
        
        