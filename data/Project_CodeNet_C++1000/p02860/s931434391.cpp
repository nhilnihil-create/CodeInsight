#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  if(a%2==1){
    cout<<"No"<<endl;
    return 0;
  }
  vector<char>vec(a/2);
  vector<char>veco(a/2);
  for(ll i=0;i<a/2;i++)cin>>vec.at(i);
  for(ll i=0;i<a/2;i++)cin>>veco.at(i);
  if(vec==veco){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
  return 0;
  
}
     
