#include<iostream>
using namespace std;
bool run(int n){


  while(n!=0){
  if(n%10==7){
    return true;
  break;}
  n=n/10;
   
  }
  return false;
};
  
  int main(){
   int n;
   cin>>n;
    if(run(n)==true){
      cout<<"Yes";
    }
    else
      cout<<"No";
    return 0;
  }