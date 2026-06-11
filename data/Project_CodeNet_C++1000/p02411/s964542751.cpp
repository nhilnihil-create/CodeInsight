#include <iostream>
using namespace std;
int main() {
  int m,f,r,t;
while(1){
  cin>>m>>f>>r;
  t=m+f;
  if(m==-1&&f==-1&&r==-1)break;
  if(m==-1||f==-1||30>t)cout<<"F"<<endl;
  else if(t>=80)cout<<"A"<<endl;
  else if(65<=t&&t<80)cout<<"B"<<endl;
  else if(50<=t&&t<65)cout<<"C"<<endl;
  else if(30<=t&&t<50){
    if(r>=50)cout<<"C"<<endl;
    else{cout<<"D"<<endl;}
    }
  }
  return 0;
}