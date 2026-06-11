#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >>n;
  bool s=false;
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      if(n==(i*j)){
        cout <<"Yes"<<endl;
        s=true;
        break;
      }
    }
    
    if(s){
      break;
    }
  }
  if(!s) {
    cout <<"No"<<endl;
  }
}