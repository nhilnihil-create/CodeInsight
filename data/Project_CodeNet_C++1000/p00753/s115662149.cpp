#include<iostream>
using namespace std;
int main(){
  int so[246913]={},n;
  for(int i=2;i<246913;i++)if(so[i]==0)for(int j=2;i*j<246913;j++)so[i*j]=1;
  while(1){
  int n,an=0;cin>>n;
  if(n==0)break;
  for(int i=n+1;i<=2*n;i++)if(so[i]==0)an++;
  cout<<an<<endl;
  }
  return 0;
}