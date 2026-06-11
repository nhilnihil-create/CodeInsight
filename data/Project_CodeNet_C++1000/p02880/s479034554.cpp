#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  for(ll i=1;i<10;i++){
    if(a%i==0){
      if(a/i<10){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
  
      
                        
                        
}
