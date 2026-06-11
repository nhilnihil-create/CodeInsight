#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(0);
  for(ll i=1;i*i<=a;i++){
    if(a%i==0){
      vec.push_back(i+a/i);
    }
  }
  sort(vec.begin(),vec.end());
  
  cout<<vec.at(0)-2<<endl;
  return 0;
  
      
                        
                        
}
