#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>veco(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<a-1;i++){
    if(vec.at(i)>=vec.at(i+1)){
      veco.at(i)=1;
    }
  }
  vector<ll>ve(0);
  for(ll i=0;i<a;i++){
    if(veco.at(i)==0){
      ve.push_back(i);
    }
  }
  ll b=ve.at(0);
  for(int i=1;i<ve.size();i++){
    b=max(b,ve.at(i)-ve.at(i-1)-1);
  }
  cout<<b<<endl;
}
    
  
