#include<iostream>
#include <cmath>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int c=0;
  if(a>=b){
    for(int i=0;i<=a-1;i++){
      c+=b*pow(10,i);
    }
    cout<<c<<endl;
  }
  else{
    for(int i=0;i<=b-1;i++){
      c+=a*pow(10,i);
    }
    cout<<c<<endl;
  }
  return 0;
}