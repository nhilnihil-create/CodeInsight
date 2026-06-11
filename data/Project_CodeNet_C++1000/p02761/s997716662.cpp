#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  int A;
  cin>>A;
  int B;
  cin>>B;
  vector<ll>vec(B);
  vector<char>veco(B);
  for(ll i=0;i<B;i++){
    cin>>vec.at(i)>>veco.at(i);
  }
  ll c=-1;
  ll d=0;
  
  if(A>=2){
    d=1;
    for(int i=1;i<A;i++){
      d=d*10;
    }
    
  }
  ll e=10;
  e=max(e,10*d);
  
  if(B==0){
    cout<<d<<endl;
    return 0;
  }
    
  for(int i=d;i<e;i++){
    
    string b=to_string(i);
    for(ll j=0;j<B;j++){
      if(b.at(vec.at(j)-1)!=veco.at(j)){
        
        break;
      }
      if(j==B-1){
        cout<<i<<endl;
        return 0;
      }
    }
  }
  cout<<c<<endl;
  return 0;
}
      
    

