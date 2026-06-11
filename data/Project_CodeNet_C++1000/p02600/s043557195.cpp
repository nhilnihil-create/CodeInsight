#include <iostream>
#include <vector>
using namespace std;

#define XGreaterLess(min, max) (min <= X) && (X <= max)

int main(){
  int X;
  cin >> X;
  
  int result = 0;
  
  if(XGreaterLess(1800, 1999)) result = 1;
  else if (XGreaterLess(1600, 1799)) result = 2;
  else if (XGreaterLess(1400, 1599)) result = 3;
  else if (XGreaterLess(1200, 1399)) result = 4;
  else if (XGreaterLess(1000, 1199)) result = 5;
  else if (XGreaterLess( 800,  999)) result = 6;
  else if (XGreaterLess( 600,  799)) result = 7;
  else if (XGreaterLess( 400,  599)) result = 8;
  
  cout << result << endl;
  return 0;
}