#include<iostream>
using namespace std;
main(){
  int a,b,max=0,min=0;
  long long int sum=0;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b;
    sum=sum+b;
    if(max<b||i==0){
      max=b;
    }
    if(min>b||i==0){
      min=b;
    }
  }
  cout<<min<<" "<<max<<" "<<sum<<endl;
}