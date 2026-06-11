#include<iostream>
using namespace std;
int main(){
  int i,k;
  for(i=1;i<=9;i++){
    for(k=1;k<=9;k++){
      cout<<i<<"x"<<k<<"="<<i*k<<endl;
    }
  }
  return 0;
}