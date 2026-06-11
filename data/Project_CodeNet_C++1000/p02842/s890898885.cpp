#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,i;
  cin>>a;
  bool B=true;
  
  for(i=0;i<50000;i++){
    b=i*108/100;
    if(a==b){
      cout<<i<<endl;
      B=false;
      break;
    }
  }
  if(B){
    cout<<":("<<endl;
  }
}