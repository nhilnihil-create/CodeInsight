#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
  double r;

  cin >> r;
  
  printf("%.6lf",r*r*3.141592653589);
  cout << " ";
  printf("%.6lf\n",2*r*3.141592653589);
  
  return 0;
}