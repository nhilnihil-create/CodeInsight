#include<iostream>
using namespace std;
int main(){

  int N,L;
  cin>>N>>L;
  int min=999999;
  for(int i=0;i<=N-1;i++){
  
    if(abs(min)>abs(L+i)){
    
      min=L+i;
    }
  }
  int allsum=0;
  for(int i=0;i<=N-1;i++){
  
    allsum+=L+i;
  }
  cout<<allsum-min;
}