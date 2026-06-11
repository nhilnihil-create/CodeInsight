#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=0;
  int ans=0;
  int t=0;
  for(int i=0;i<3;i++){
    if(s[i]=='R'){
      t++;
    }
  }
  if(t==3){
    ans=3;
  }
  if(t==0){
    ans=0;
  }
  if(t==1){
    ans=1;
  }
  if(t==2){
    if(s[1]=='R'){
      ans=2;
    }
    else{
      ans=1;
    }
  }
  cout<<ans<<endl;

}