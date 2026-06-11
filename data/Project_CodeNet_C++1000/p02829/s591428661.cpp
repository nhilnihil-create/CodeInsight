#include<iostream>

using namespace std;

main(){
  int A,B;
  cin>>A>>B;
  if(A==1){
    if(B ==2)cout<<3<<endl;
    else cout<<2<<endl;
  }
  else if(A==2){
    if(B ==1)cout<<3<<endl;
    else cout<<1<<endl;
  }
  else{
    if(B ==2)cout<<1<<endl;
    else cout<<2<<endl;
  }
  return 0;
}