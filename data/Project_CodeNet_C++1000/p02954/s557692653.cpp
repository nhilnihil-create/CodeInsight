#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  string str;
  cin>>str;
  for(ll i=0;i<(ll)str.size();i++){
    if(str.at(i)=='R'){
      ll x=0;
      ll y=0;
      while(str.at(i)=='R'){
        i++;
        x++;
      }
      while(str.at(i)=='L'){
        i++;
        y++;
        if(i==(ll)str.size()){break;}
      }
      for(ll i=0;i<x-1;i++){cout<<0<<" ";}
      cout<<x/2+x%2+y/2<<" "<<x/2+y%2+y/2<<" ";
      for(ll i=0;i<y-1;i++){cout<<0<<" ";}
    }
    if(i==(ll)str.size()){break;}
    i--;
  }
}