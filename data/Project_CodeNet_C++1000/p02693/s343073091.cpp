#include<iostream>
using namespace std;
bool run(int n,int a,int b){
  for(int i=a;i<=b;i++){
    if(i%n==0){
      return true;
      break;
    }
  }
    return false;
}
 
int main(){
   int n,a,b;
  cin>>n>>a>>b;
  if(run(n,a,b)==true)
    cout<<"OK";
  else
    cout<<"NG";
 
  return 0;
}