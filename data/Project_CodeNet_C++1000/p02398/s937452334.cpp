#include<iostream>

int main(){
 int a, b, c, f = 0;
 std::cin >> a >> b >> c;
 
 for(int x = a; x <= b; x++ ){
  if(c % x == 0) f++;
  }
 
 std::cout<< f <<"\n";

 return 0;
}