#include<bits/stdc++.h>
int main(){
  int h,w,a,b;
  std::cin>>h>>w>>a>>b;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      std::cout<<((i<b)==(j<a))?"0":"1";
    }
    std::cout<<std::endl;
  }
}
