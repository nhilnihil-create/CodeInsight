#include <bits/stdc++.h>
using namespace std;

int main(){
  int M,D;
  cin>>M>>D;
  int j1,j2;
  int cnt=0;
  for(int i=1;i<=M;i++){
    for(int j=1;j<=D;j++){
      if(j<=9) continue;
      j1=j%10;
      j2=j/10;
      if(j1==1 || j2==1) continue;
      if(j1*j2==i){
        cnt++;
        //cout<<j1<<" "<<j2<<" "<<i<<" "<<endl;
      }
    }
  }
  cout<<cnt<<endl;

  return 0;
}
