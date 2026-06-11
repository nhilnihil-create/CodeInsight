#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  string k="Sunny";
  string p="Rainy";
  string t="Cloudy";
  if(s==k){
    cout<<t;
  }
  else if(s==p){
  cout<<k;
  }
  else{
    cout<<p;
  }
return 0;
}