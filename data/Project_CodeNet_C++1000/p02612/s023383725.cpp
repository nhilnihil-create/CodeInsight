#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<100;i++){
    if(n<=1000*i){
      cout<<1000*i-n;
      break;
    }
    else
      continue;
  }
  return 0;
}