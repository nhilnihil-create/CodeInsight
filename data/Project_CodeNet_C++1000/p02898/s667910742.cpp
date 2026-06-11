#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  ll d=0;
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    if(c>=b){
      d+=1;
    }
  }
  cout<<d<<endl;
  return 0;
  
  
      
                        
                        
}
