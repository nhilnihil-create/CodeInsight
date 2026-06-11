#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin>>X;
  int ans,yakusu;
  for(int i=X;i<=100003;i++){
    yakusu=0;
    for(int j=1;j<=i;j++){
      if(i%j==0){
        yakusu++;
      }
    }
    if(yakusu==2){
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
}