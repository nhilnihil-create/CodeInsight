#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {

  string S;cin>>S;
  
  int ans=0;
  
  if(S.size()%2==0){
    for(int i=0;i<S.size()/2;i++){
      if(S.at(i)==S.at(S.size()-i-1)){
        ans += 0;
      }
      else{
        ans++;
      }
    }
  }
  
  else if(S.size()%2==1){
    for(int i=0;i<(S.size()-1)/2;i++){
      if(S.at(i)==S.at(S.size()-i-1)){
        ans +=0;
      }
      else{
        ans++;
      }
    }
  }
  
  cout<<ans<<endl;
}