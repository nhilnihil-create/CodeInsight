#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
  int a, b;

  cin >> a >> b;

  // ????????????
  int d = a / b;
  int r = a % b;
  double f = (double)a / b;

  //cout << d << " " << r << " " << f << endl;
  // cout << (a / b) << " " << (a % b) << " " << ((double)a / b) << endl;
  printf("%d %d %lf\n", d, r, f);
  
  return 0;
}