#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string S;
  cin>>S;
  ll N=S.size();
  for(ll i=0;i<N;i++) {
    
if(i%2==0&&S[i]=='L') {
cout<<"No"<<endl;
  return 0;
}
    if(i%2!=0&&S[i]=='R') {
cout<<"No"<<endl;
    return 0;
    }
  }
  
  
  
  cout<<"Yes"<<endl;
}
