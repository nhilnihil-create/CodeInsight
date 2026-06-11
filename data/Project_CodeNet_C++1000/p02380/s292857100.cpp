// Lec10-B Triangle
#include<iostream>
#include<cmath>
#include<iomanip>
int main(){
  int a, b, C;
  std::cin >> a >> b >> C;
  std::cout << std::fixed << std::setprecision(8) << a*b*sin(C*M_PI/180)/2 << std::endl;
  std::cout << std::fixed << std::setprecision(8) << a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(C*M_PI/180)) << std::endl;
  std::cout << std::fixed << std::setprecision(8) << b*sin(C*M_PI/180) << std::endl;
  return 0;
}