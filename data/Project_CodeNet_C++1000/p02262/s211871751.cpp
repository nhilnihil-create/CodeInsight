#include<iostream>
using namespace std;
int main(){
  int n,a[1000000],cnt=0,m=0,g[1000000];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=1;i<=n;i=3*i+1)g[m]=i,m++;
  for(int i=m-1;i>=0;i--){
    for(int j=g[i];j<n;j++){
      int v=a[j],k=j-g[i];
      while(k>=0&&a[k]>v){
	a[k+g[i]]=a[k];
	k=k-g[i];
	cnt++;
      }
      a[k+g[i]]=v;
    }
  }
  cout<<m<<endl;
  for(int i=m-1;i>=0;i--){
    cout<<g[i];
    i==0?cout<<endl:cout<<" ";
  }
  cout<<cnt<<endl;
  for(int i=0;i<n;i++)cout<<a[i]<<endl;
  return 0;
}