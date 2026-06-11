#include<iostream>
using namespace std;
int main()
{
  int x,y;
  cin>>x>>y;
  if(x==1){
    if(y==1){
      cout<<"1000000";
    }
    else if(y==2){
      cout<<"500000";
    }
    else if(y==3){
      cout<<"400000";
    }
    else{
      cout<<"300000";
    }
  }
  else if(x==2){
    if(y==1){
      cout<<"500000";
    }
    else if(y==2){
      cout<<"400000";
    }
    else if(y==3){
      cout<<"300000";
    }
    else{
      cout<<"200000";
    }
  }
 else if(x==3){
    if(y==1){
      cout<<"400000";
    }
    else if(y==2){
      cout<<"300000";
    }
    else if(y==3){
      cout<<"200000";
    }
    else{
      cout<<"100000";
    }
  }
 else {
    if(y==1){
      cout<<"300000";
    }
    else if(y==2){
      cout<<"200000";
    }
    else if(y==3){
      cout<<"100000";
    }
    else{
      cout<<"0";
    }
  }
}
