#include<iostream>
using namespace std;
int main(){
int n,f=0;
  cin>>n;
  for(int i=0;i<n;i++){
     int x;
    cin>>x;
    if(x%2==0){
    if((x%3)!=0 && (x%5)!=0 )
     {
      f=1;
     }
    }
  }
  if(f==1){
  cout<<"DENIED";
  }
  else
    cout<<"APPROVED";
}