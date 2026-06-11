#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int flag=1;
  for(int i;i<(s.size()-1)/2;i++){
    if(s.at(i)!=s.at(s.size()-1-i)){
      flag=0;
    }
  }
  for(int i;i<(s.size()-1)/4;i++){
    if(s.at(i)!=s.at((s.size()/2)-1-i)){
      flag=0;
    }
  }
  if(flag==1){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}