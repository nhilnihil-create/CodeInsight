#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  int a=1,b=1;
  while(b!=9||a!=9){
    cout<<a<<"x"<<b<<"="<<a*b<<endl;
    if(b==9){
      b=1,a++;
    }else{
      b++;}
  }
  cout<<"9x9=81"<<endl;

  return 0;
}