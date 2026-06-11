#include <iostream>
#include<stdio.h>
using namespace std;


int main()
{
  int a,b;
  double f1,f2;
  
  cin >> a >> b;
  f1=(double)a;
  f2=(double)b;

  cout << a/b << " " << a%b << " ";
  printf("%.8lf\n", f1/f2);

  
  return 0;
}