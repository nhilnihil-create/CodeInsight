#include<iostream>
using namespace std;
int main(){
  int N,X,T,tem=0;
  cin>>N>>X>>T;
  while(N>=X)
  {
    N=N-X;
    tem=tem+T;
  }
  if(N==0){
  cout<<tem<<endl;
  }
    else
      cout<<tem+T;
  return 0;
}
