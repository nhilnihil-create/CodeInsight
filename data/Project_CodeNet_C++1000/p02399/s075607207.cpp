#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]){
  int a,b,d,r;
  double f,da,db;
  cin >> a;
  cin >> b;
  d = a/b;
  r = a % b;
  da = static_cast<double>(a);
  db = static_cast<double>(b);
  f = da / db;
  printf("%d %d %lf\n",d,r,f);
  //cout << d << " " << r << " " << f << endl;
  return 0;
}