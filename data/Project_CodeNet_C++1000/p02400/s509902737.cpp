#include<iostream>
#include<math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int main(void){
  double a;
  cin>>a;
  cout<< fixed << setprecision(6)<<a*a*M_PI<<" "<<2*a*M_PI<<endl;
  return 0;
}