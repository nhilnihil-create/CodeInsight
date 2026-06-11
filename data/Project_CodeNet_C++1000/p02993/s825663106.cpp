#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S;
  cin>>S;
  for(ll i=0;i<3;i++) {
    if(S[i]==S[i+1]) {
      cout<<"Bad"<<endl;
      return 0;
    }
  }
  
  cout<<"Good"<<endl;
}
  

