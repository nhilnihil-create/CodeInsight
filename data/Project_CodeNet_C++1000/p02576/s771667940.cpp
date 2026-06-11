#include<iostream>
using namespace std;

int main(){
  int n,x,t,k;
  cin>>n>>x>>t;
  if(n%x>0){
    k=1;
  }
  else{
    k=0;
  }
  cout<<t*(n/x+k)<<endl;
}
