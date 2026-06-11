#include<iostream>
using namespace std;
int main(){
  long long int H;
long long int W;
  cin>>H>>W;
  if(H!=1&&W!=1){
  if((H*W)%2==0){
  cout<<H*W/2;
  }
  else{
  cout<<(H*W)/2+1;
  }
  }
  else {
  cout<<1;
  }
}