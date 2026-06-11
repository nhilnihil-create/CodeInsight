#include<iostream>
using namespace std;
int main (void)
{
 int n,m,i,j,k,a[1000000];
  cin>>n>>m;
  for(i=0;i<m;i++){cin>>a[i];}
  for(i=0;i<m;i++){n=n-a[i];}
  if(n>=0){cout<<n;}
  else{cout<<"-1";}

}