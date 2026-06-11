#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int taka=0,ao=0;
  if(c%b==0){
    taka+=c/b;
  }
  else{
    taka+=c/b+1;
  }
  if(a%d==0){
    ao+=a/d;
  }
  else{
    ao+=a/d+1;
  }
  if(taka<=ao){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}