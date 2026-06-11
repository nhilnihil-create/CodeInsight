#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  for(ll i=0;i<(b-1)/2+1;i++){
    if(a.at(2*i)=='L'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  for(ll i=0;i<b/2;i++){
    if(a.at(2*i+1)=='R'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
  
  
  
      
                        
                        
}
