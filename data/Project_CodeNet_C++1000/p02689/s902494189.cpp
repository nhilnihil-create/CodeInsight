#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n, m;
  std::cin>>n>>m;
  int  h[n] ,ma[n];
  for(int i=1;i<=n;i++){
    std::cin>>h[i];
    ma[i]=0;
  }
  
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    ma[a]=std::max(ma[a],h[b]);
    ma[b]=std::max(ma[b],h[a]);
  }
  
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=h[i]>ma[i];
  }
  
  std::cout << ans;
}
