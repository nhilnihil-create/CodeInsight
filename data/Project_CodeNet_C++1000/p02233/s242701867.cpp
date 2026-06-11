#include<bits/stdc++.h>
using namespace std;
main(){
  int a[44],n;
  a[0]=a[1]=1;
  cin>>n;
  for(int i=2;i<=n;i++)a[i]=a[i-1]+a[i-2];
  cout<<a[n]<<endl; 
}
