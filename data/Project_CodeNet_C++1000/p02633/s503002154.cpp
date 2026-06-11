#include<bits/stdc++.h>
using namespace std;
 int main(){
  int X;
  cin>>X;
  int k=0,n=1;
  while(true){
    if(360*n%X==0){
      cout<<360*n/X<<endl;
      break;
    }
    else{
      n++;
    }
  }
 }