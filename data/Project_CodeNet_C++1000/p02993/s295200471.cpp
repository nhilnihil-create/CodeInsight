#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  
  vector<char>vec(4);
  for(ll i=0;i<4;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<3;i++){
    if(vec.at(i)==vec.at(i+1)){
      cout<<"Bad"<<endl;
      return 0;
    }
  }
  cout<<"Good"<<endl;
  return 0;
}
