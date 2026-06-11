#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  ll c=a%2019;
  ll d=b%2019;
  if(d<=c){
    cout<<0<<endl;
    return 0;
  }
  if(b-a>d-c){
    cout<<0<<endl;
    return 0;
  }
  ll f=c*(c+1);
  for(ll i=c+1;i<d+1;i++){
    for(ll j=c;j<i;j++){
      f=min(f,i*j%2019);
    }
  }
  cout<<f<<endl;
    
      
}
