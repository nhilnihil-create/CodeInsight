#include<iostream>
#define MAX 300000
using namespace std;
int main(){
  bool prime[MAX]={1,1,0};
  for(int i=3;i<MAX;i+=2){
    if(prime[i])continue;
    for(int j=3*i;j<MAX;j+=2*i)prime[j]=1;
  }
  int n;
  while(cin>>n,n){
    int co=0;
    for(int i=n+1;i<=2*n;i++){
      if(i!=2&&i%2==0)continue;
      if(prime[i]==0)co++;
      //cout<<i<<endl;
    }
    cout<<co<<endl;
  }
}