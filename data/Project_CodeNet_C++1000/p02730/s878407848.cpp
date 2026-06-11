#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<=s.size()-1;i++){
    if(s[i]==s[s.size()-i-1]){
      continue;
    }
    else{
      cnt=-1;
    }
  }
  for(int i=0;i<=(s.size()-1)/2-1;i++){
    if(s[i]==s[(s.size()-1)/2-i-1]){
      continue;
    }
    else{
      cnt=-1;
    }
  }
  for(int i=(s.size()+3)/2-1;i<=s.size()-1;i++){
    if(s[i]==s[s.size()-1+(s.size()+3)/2-1-i]){
      continue;
    }
    else{
      cnt=-1;
    }
  }
  
  if(cnt==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}