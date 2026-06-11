#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  
  int odd=0;
  int even=0;
  
  for(int i=0;i<S.size();i++){
    if(i%2==0){
      if(S[i]=='R'||S[i]=='U'||S[i]=='D'){
        even++;
      }
    }
    else{
      if(S[i]=='L'||S[i]=='U'||S[i]=='D'){
        odd++;
      }
    }
  }
  
  if(S.size()%2==0){
    if(even==S.size()/2&&odd==even){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  else{
    if(even==S.size()/2+1&&even==odd+1){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}