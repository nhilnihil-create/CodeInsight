#include<iostream>
#include<math.h>
using namespace std;

int main(){
  while(1){
  int m[300000]={};
  int count=0;
  int n;
  cin>>n;
  if(n==0) break;
  m[1]=1;
  for(int j=2;j<=sqrt(2*n);j++){
    if(m[j]==0){
      for(int i=2;i<=(2*n)/j;i++){
    m[i*j]=1;
    }
    }
  }
  for(int i=n+1;i<=2*n;i++)    if(m[i]==0)count++;
  cout<<count<<endl;
  }
  return 0;
}