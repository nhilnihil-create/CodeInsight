#include<bits/stdc++.h>
int main(){
  int h,w,a,b;
  std::cin>>h>>w>>a>>b;
  for(int i=0;i<b;i++){
    for(int j=0;j<a;j++){
      std::cout<<"1";
    }
    for(int j=a;j<w;j++){
      std::cout<<"0";
    }
    std::cout<<std::endl;
  }
  for(int i=b;i<h;i++){
    for(int j=0;j<a;j++){
      std::cout<<"0";
    }
    for(int j=a;j<w;j++){
      std::cout<<"1";
    }
    std::cout<<std::endl;
  }
}