/**
 * Triangle.cpp
 * Create:20180430
 * Description:三角形の２辺a,bとその間の角cから
 * 面積と外周の長さ、aを底辺としたときの高さを求めるプログラム
 */
#include <iostream>
#include <cmath>

double radian(int c){
  return (double)c * M_PI / 180;
}

double area(double a, double b, double radC){
  double area = (a * b * sin(radC)) / 2;
  return area;
}

double outer(double a, double b, double radC){
  double outer = a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(radC)));
  return outer;
}

double a_height(double a, double b, double radC){
  return (area(a, b, radC) * 2) / a;
}

int main(int argc, char* argv[]){
  double a, b;
  int c;

  std::cin >> a >> b >> c;
  double rad = radian(c);
  printf("%.8f\n", area(a, b, rad));
  printf("%.8f\n", outer(a, b, rad));
  printf("%.8f\n", a_height(a, b, rad));

  return 0;
}
