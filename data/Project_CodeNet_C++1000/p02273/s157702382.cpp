#include <iostream>
#include <cmath>
using namespace std;

void koch(double x0, double y0, double x1, double y1, int n){
  if(n == 0){
    cout << x0 << " " << y0 << endl;
  } else {
    double x01 = x0 + (x1-x0)/3;
    double y01 = y0 + (y1-y0)/3;
    double x02 = x0 + (x1-x0)/2 - (y1-y0)*sqrt(3)/6;
    double y02 = y0 + (y1-y0)/2 + (x1-x0)*sqrt(3)/6;
    double x03 = x0 + (x1-x0)*2/3;
    double y03 = y0 + (y1-y0)*2/3;

    koch(x0, y0, x01, y01, n-1);
    koch(x01, y01, x02, y02, n-1);
    koch(x02, y02, x03, y03, n-1);
    koch(x03, y03, x1, y1, n-1);
  }
}

int main(){
    int n;
    cin >> n;
    koch(0,0,100,0,n);
    cout << 100 << " " << 0 << endl;
}