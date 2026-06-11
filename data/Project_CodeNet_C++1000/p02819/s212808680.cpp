#include <bits/stdc++.h>
using namespace std;
int func(int x){
  for(int i=2;i<x;i++){
    if(x%i==0){
    return 0;
    }
  }
  return 1;
}


int main(){
  
   int N;
  cin>>N;
  bool a=false;
  while(a==false){
    if(func(N)==0){
      N++;
    }
    else if(func(N)==1){
      a=true;
      cout<<N<<endl;
    }
  }
}