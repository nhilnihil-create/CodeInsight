#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
  int a;
  int b;
  int d;
  int r;
  double f;
  
  cin >> a >>b;
  d=a/b;
  r=a%b;
  f=(double)a/(double)b;
  
  cout << d <<" "<< r <<" "<< fixed << f <<"\n";
}