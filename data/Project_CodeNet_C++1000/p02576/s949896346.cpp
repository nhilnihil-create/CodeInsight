#include<iostream>
using namespace std;

int main(){
  int N,X,T;
  int a;
  cin>>N>>X>>T;
  a=N/X;
  if(N%X==0){
    cout<<T*a<<endl;
  }else{
    cout<<T*(a+1)<<endl;
  }
  return 0;
}
