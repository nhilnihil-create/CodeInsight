#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S;
  cin>>S;
  for(ll i=0;i<4;i++) {
    ll count=0;
for(ll j=0;j<4;j++) {
  if(S[i]==S[j]) {
count++;
  }
}

    if(count!=2) {
      cout<<"No"<<endl;
      return 0;
    }
  }


  cout<<"Yes"<<endl;
}
