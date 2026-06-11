#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
  double x,y,x1,y1;
  cin>>x>>y>>x1>>y1;
  printf("%.8f\n",sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)));
  return 0;
}