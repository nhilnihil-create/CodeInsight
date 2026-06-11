#include<iostream> 

int main(){ 
  int a,b,c; 
  std::cin >> a >> b >> c; 
  std::swap(a,b); 
  std::swap(a,c); 
  std::cout<<a<<" "<<b<<" "<< c <<std::endl; 
 
}