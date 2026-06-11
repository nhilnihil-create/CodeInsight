#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long H,W;
  cin>>H>>W;
  if(H==1||W==1){
    cout<<1<<endl;
  }
  else{
    if(H%2==0){
      cout<<H*W/2<<endl;
    }
    if(H%2==1&&W%2==1){
      cout<<H*W/2+1<<endl;
    }
    if(H%2==1&&W%2==0){
      cout<<H*W/2<<endl;
    }
  }
}