#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >>S;
  int len=S.length();
  if(len==1){
    cout<<1<<endl;
    return 0;
  }
  int cnt=len-1;
  for(int i=0;i<len-1;i++){
    if(S.at(i)==S.at(i+1)){
      i+=2;
      cnt--;
      }
  }
  cout<<cnt+1<<endl;
  return 0;
}

  
  
  
  