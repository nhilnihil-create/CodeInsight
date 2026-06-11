#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin>>a>>b;
  int price=0;
  if(a==1){
    price+=300000;
  }else if(a==2){
    price+=200000;
  }else if(a==3){
    price+=100000;
  }
  if(b==1){
    price+=300000;
  }else if(b==2){
    price+=200000;
  }else if(b==3){
    price+=100000;
  }
  if(a==1 && b==1){
    price+=400000;
  }
  cout<<price<<endl;
}