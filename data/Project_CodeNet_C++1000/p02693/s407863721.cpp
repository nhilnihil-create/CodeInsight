#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,K;
  bool ans=false;
  cin>>K>>A>>B;
  
  for(int i=A; i<=B; i++){
    if(i%K==0) {
      ans=true;
      break;
    }
  }
  if(ans) cout<<"OK";
  else cout<<"NG";
}