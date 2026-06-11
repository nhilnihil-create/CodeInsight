#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#include <sstream>

using namespace std;

void printCoffo(double x1, double y1, double x5, double y5, int n){

  if(n<=0){
    return;
  }
  double x2,y2,x3,y3,x4,y4;
  x2 = (2.0*x1+x5)/3.0;
  y2 = (2.0*y1+y5)/3.0;
  x4 = (x1+2.0*x5)/3.0;
  y4 = (y1+2.0*y5)/3.0;

  x3 = x2 + (x4-x2)/2.0 - sqrt(3.0)*(y4-y2)/2.0;
  y3 = y2 + sqrt(3.0)*(x4-x2)/2.0 + (y4-y2)/2.0;

  printCoffo(x1, y1, x2, y2, n-1);
  cout << x2 << " " << y2 <<endl;
  printCoffo(x2, y2, x3, y3, n-1);
  cout << x3 << " " << y3 << endl;
  printCoffo(x3, y3, x4, y4, n-1);
  cout << x4 << " " << y4 << endl;
  printCoffo(x4, y4, x5, y5, n-1);
  
}
  

int main(){
  int n;
  cin >> n;

  double x1,y1,x2,y2;
  x1 = 0.0;
  y1 = 0.0;
  x2 = 100.0;
  y2 = 0.0; 

  cout << x1 << " " << y1 << endl;
  printCoffo(x1, y1, x2, y2, n);
  cout << x2 << " " << y2 << endl;
  
}