#include <bits/stdc++.h> 
typedef long long ll; 
using namespace std; 
int main() { 
  string s;
  cin>>s; 
  bool f=true; 
  for(int i=0;i<s.length();i++){
    if(i%2==0){ 
      if(s.substr(i,1)!="h")f=false;
    }else{ if(s.substr(i,1)!="i")f=false; 
         }
  } 
  if(s.length()%2!=0)f=false;
  if(f){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
    } 
  return 0; 
} 

