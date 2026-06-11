#include<bits/stdc++.h>
using namespace std;

int main(){
 int N,X,T,t;
  cin>>N>>X>>T;
  if(N%X==0){
 t=(N/X)*T;
  }
  else{
  t=(N/X+1)*T;
  }
  cout<<t<<endl;
  
}