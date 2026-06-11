#include <bits/stdc++.h>
using namespace std;
int main(){
  int K,A,B;
  cin>>K>>A>>B;
  bool Q=false;
  for(int i=1;i<25252;i++){
    if(A<=i*K&&i*K<=B){
      Q=true;
      break;
    }
  }
  if(Q){
    cout<<"OK"<<endl;
  }
  else{
    cout<<"NG"<<endl;
  }
}