#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  int n;
  //while(1){
    cin >> n;
    int x[100] = {0}, y[100] = {0};
    for ( int i = 0; i < n; i++ ) cin >> x[i];
    for ( int i = 0; i < n; i++ ) cin >> y[i];
    double Dxy = 0;
    for ( int p = 1; p <= 3; p++) {
      double dxy = 0;
      for ( int i = 0; i < n; i++ ) dxy += pow( fabs(x[i] - y[i]), p);
      Dxy = pow( dxy, 1.0/p);
      printf ("%lf\n", Dxy);
    }
    Dxy = 0;
    for ( int i = 0; i < n; i++ ) {
      Dxy = max(Dxy, fabs(x[i]-y[i]) );
    }
    printf ("%lf\n", Dxy);
    
    return 0;
 }
