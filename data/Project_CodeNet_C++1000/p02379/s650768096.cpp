#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#define MAXSIZE 101
#define PI 3.141592653589
using namespace std;
int main(){
  double x1,y1,x2,y2;
  std::cin >> x1>>y1>>x2>>y2;
  printf("%.8f\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}