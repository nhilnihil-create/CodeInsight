#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a;
  cin>>a;
  ll c=1;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    if(vec.at(i)!=0&&c>0){
     if(1000000000000000000/vec.at(i)<c){
       c=-1;
     }
      else{
        c=c*vec.at(i);
      }
    }
    else if(vec.at(i)==0){
      c=0;
    }
  }
  cout<<c<<endl;  
}
