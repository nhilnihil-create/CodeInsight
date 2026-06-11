#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
  int a,b;
  double c;
  cin>>a>>b;
  c=(double)a/b;
  printf("%d %d %f\n",a/b,a%b,c);
  return 0;
}