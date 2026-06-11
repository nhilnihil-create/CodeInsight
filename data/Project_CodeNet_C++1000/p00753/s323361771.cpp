#include <iostream>
using namespace std;

int main(){
  int n;
  bool prime[300005];
  for(int i=2;i<300000;i++)prime[i]=true;
  
  for(int i=2;i<300000;i++){
    for(int j=1;i*j<300000;j++){
      if(i!=i*j&&i*j<300000)prime[i*j]=false;
    }
  }
  
  while(1){
    cin>>n;
    if(n==0)break;
    int cnt=0;
    for(int i=n+1;i<=2*n;i++)if(prime[i])cnt++;
    cout<<cnt<<endl;
  }
  
  return 0;
}