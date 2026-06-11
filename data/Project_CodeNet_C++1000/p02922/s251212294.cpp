#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  if(b==1){
    cout<<0<<endl;
  }
  else if(b==2){
    cout<<1<<endl;
  }
  else{
  cout<<(b-2)/(a-1)+1<<endl;
  return 0;}
  
}
