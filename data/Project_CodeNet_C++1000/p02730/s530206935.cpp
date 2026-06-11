#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string a;
  cin>>a;
  ll b=a.size();
  ll c=(b-1)/2;
  for(ll i=0;i<c/2+1;i++){
    if(a.at(i)!=a.at(c-i-1)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  for(ll i=0;i<c+1;i++){
    if(a.at(i)!=a.at(c-i+c)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
      
  
}
