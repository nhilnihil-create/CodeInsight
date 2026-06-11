#include<iostream>
using namespace std;
#define MAX 1000000
bool isP[MAX];
int n,sumP[MAX];
int main(){
  for(int i=2;i<MAX;i++)isP[i]=true;
  for(int i=2;i*i<=MAX;i++)
    if(isP[i])for(int j=i*i;j<MAX;j+=i)isP[j]=false;
  for(int i=2;i<MAX;i++)sumP[i]=isP[i]+sumP[i-1];
  while(1){
    cin>>n;
    if(n==0)break;
    cout<<sumP[n+n]-sumP[n]<<endl;
  }
  return 0;
}