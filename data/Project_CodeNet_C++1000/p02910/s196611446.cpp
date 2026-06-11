#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool aw=false;
  for(int i=0;i<s.size();i+=2){
    if(s[i]=='L'){
      aw=true;
    }
  }
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='R'){
      aw=true;
    }
  }
  if(aw) cout<<"No"<<endl;
  else   cout<<"Yes"<<endl;
}
  

      
