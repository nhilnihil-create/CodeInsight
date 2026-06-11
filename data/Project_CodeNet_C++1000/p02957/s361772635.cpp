#include "iostream"
using namespace std;
int asb(int a){
  if(a<0){
    return(-1*a);
  }
  else{
    return(a);
  }
}
int main(){
  long long a;long long b;
  cin>>a>>b;
  long long d=(a+b)/2;
  if((asb(a-d))==(asb(b-d))){
    cout<<d<<endl;
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }


}
