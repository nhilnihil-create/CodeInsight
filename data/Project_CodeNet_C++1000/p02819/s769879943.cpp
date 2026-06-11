#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long X;
  cin>>X;
  
  
  int ans=0;
  
  if(X==2){
    ans=2;
  }
  else if(X==3){
    ans=3;
  }
  else{
    while(true){
      bool check=true;
      for(int i=2;i<=pow(X,0.5);i++){
        if(X%i==0){
          check=false;
        }
      }
      if(check){
        ans=X;
        break;
      }
      X++;
    }
  }
  cout<<ans<<endl;
}