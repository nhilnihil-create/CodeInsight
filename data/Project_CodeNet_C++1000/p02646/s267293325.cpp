#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
  int a,b;
  int v,w;
  int t;
  cin>>a>>v;
  cin>>b>>w;
  cin>>t;
  
  b=abs(b-a);
  v-=w;

  if(v<=0){
    cout<<"NO"<<endl;
  }else if((b+v-1)/v <= t){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return(0);
}