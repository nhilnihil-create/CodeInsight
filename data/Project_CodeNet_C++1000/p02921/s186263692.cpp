#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<char>vec(3);
  for(ll i=0;i<3;i++){
    cin>>vec.at(i);
  }
  ll a=0;
  for(ll i=0;i<3;i++){
    char d;
    cin>>d;
    if(vec.at(i)==d){
      a+=1;
    }
  }
  cout<<a<<endl;
  return 0;
}
  
    
