#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  string h = "";
  for (int i=0;i<5;++i){
    h+="hi";
    if (h==s){
      cout<<"Yes";
      return 0;
    }
  }
  cout<<"No";
}