#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
using namespace std;


int main(){

  int a, b;
  cin >> a >> b;
  double f = a*1.0 / b*1.0;
  printf("%d %d %.8lf\n", a/b, a%b, f);

  return 0;
}








// EOF