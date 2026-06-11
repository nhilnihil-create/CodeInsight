#include<bits/stdc++.h>
int n,m,i,d,p,z;
main(){
  while(std::cin>>n>>m,n){
    int x[11]={};
    for(z=i=0;i++<n;x[p]+=d)std::cin>>d>>p;
    for(i=10;i>=0;z+=i*x[i],--i)x[i]-=d=(x[i]<m?x[i]:m),m-=d;
    std::cout<<z<<'\n';
  }
}