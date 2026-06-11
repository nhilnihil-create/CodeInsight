#include<bits/stdc++.h>
using namespace std;

int main(){
  int ans=0;
  int tmp;
  for(int i=0;i<3;i++){
    cin >>tmp;
    ans+=tmp;
  }
  if(ans>=22){
    cout <<"bust"<<endl;
    return 0;
  }
  else{
    cout <<"win"<<endl;
    return 0;
  }
}