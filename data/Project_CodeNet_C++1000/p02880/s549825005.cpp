#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  for(ll i=1;i<10;i++) {
if(N%i==0&&N/i<10) {
cout<<"Yes"<<endl;
  return 0;
}
  }
  
  cout<<"No"<<endl;
}
