#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a;
  int ans=0;
  for(int i=1;i<=n;i++){
    cin>>a;
    if(a%2==0 & (a%3!=0 & a%5!=0)){
      ans-=1;
    }
  }
  if(ans>=0){
    cout<<"APPROVED"<<endl;
  }
  else{
    cout<<"DENIED"<<endl;
  }
}