#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  string t="";
  for(int i=0;i<5;++i){
    t+="hi";
    if(s==t){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}