#include<iostream>

int main(){
  int s,w;
  std::cin>>s>>w;
  if(w>=s)
    std::cout<<"unsafe\n";
  else
    std::cout<<"safe\n";
}
