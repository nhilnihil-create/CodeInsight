#include<iostream>
using namespace std;
int main(){
  int n,o,p,x;
  x=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>o>>p;
    if(o==p){
      x++;
      if(x==3){
        i=n;
      }
    }else{
      x=0;
    }
  }if(x==3){
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
  return 0;
}