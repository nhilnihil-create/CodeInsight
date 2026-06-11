#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <cmath>
using namespace std;

int main() {
  double a,b,h,m;
    cin >>a>> b>>h>>m;
    
    static const double pi = 3.141592653589793;
    
    double c;
    c = 30*h+m/2-6*m;
  
    cout << fixed << setprecision(12);
    cout <<sqrt(a*a+b*b -2*a*b*cos(pi/(180/c)));
}