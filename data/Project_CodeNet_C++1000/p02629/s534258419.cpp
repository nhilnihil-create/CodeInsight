#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<ll>>;
int main(){
  ll a;
  cin>>a;
  
  vector<ll>vec(0);
  for(ll i=0;;i++){
    ll b=a%26;
    if(b==0){
      b=26;
      a=a-26;
    }
    vec.push_back(b);
    a=a/26;
    if(a==0){
      break;
    }
  }
  reverse(vec.begin(),vec.end());
  for(ll i=0;i<vec.size();i++){
    
    char c='a'+vec.at(i)-1;
    cout<<c;
  }
  cout<<endl;
}