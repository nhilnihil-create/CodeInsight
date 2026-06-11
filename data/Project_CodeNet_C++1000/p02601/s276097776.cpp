#include<iostream>
using namespace std;

int main(){
  int i=0;
  int j=0;
  int a,b,c;
  cin>>a>>b>>c;
  int k;
  cin>>k;
  while(1){
    if(a<b)break;
    i++;
    b*=2;
  }
  while(1){
    if(b<c)break;
    j++;
    c*=2;
  }
  if(k<(i+j)){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
  return 0;
}