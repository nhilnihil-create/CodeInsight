#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double x[100],y[100];

double dist(int n, int p) {
  int i;
  double d=0;
  for(i=0;i<n;i++) {
    d+=pow(abs(x[i]-y[i]),p);
  }
  double pp=1.0/p;
  d=pow(d, pp);
  return d;
}

int main(){
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    cin >> x[i];
  }
  for(i=0;i<n;i++) {
    cin >> y[i];
  }
  double d1=dist(n, 1),d2=dist(n, 2),d3=dist(n, 3);
  double d4=0;
  for (i=0;i<n;i++) {
    if (abs(x[i]-y[i]) > d4) {
      d4 = abs(x[i]-y[i]);
    }
  }
  cout << fixed;
  cout << std::setprecision(5) << d1 << endl << d2 << endl << d3 << endl << d4 << endl;
  return 0;
}

