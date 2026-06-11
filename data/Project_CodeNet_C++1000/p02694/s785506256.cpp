#include <iostream>

int main(){
 long long X;
 std::cin>>X;

 long long a=100;

 int count=0;
 while(a<X){
  count++;
  a+=a/100;
 }

 std::cout<<count<<std::endl;
 
}