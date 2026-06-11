// Lec10-A Distance
#include<iostream>
#include<cmath>
#include<iomanip>
int main(){
  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cout << std::fixed << std::setprecision(8) << sqrt(pow(x1-x2,2)+pow(y1-y2,2)) << std::endl;
  return 0;
}