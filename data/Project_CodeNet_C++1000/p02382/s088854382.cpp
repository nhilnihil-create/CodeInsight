#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int i, j, n, p;
  int x[100], y[100];
  double sum, d;
  
  cin >> n;

  for( i = 0; i < n; i++ ) cin >> x[i];
  for( i = 0; i < n; i++ ) cin >> y[i];

  // when 1 <= p <= 3
  for( p = 1; p <= 3; p++ ){
    sum = 0;
    for( i = 0; i < n; i++ ){
      sum += pow( fabs( x[i] - y[i] ), p );
    }
    printf("%lf\n", pow( sum, 1.0/p ) );
  }

  // when p is unlimited
  for( i = 0; i < n; i++ )
    d = d < fabs( x[i] - y[i] ) ? fabs( x[i] - y[i] ) : d;  
  printf("%lf\n", d);
  
  return 0;
}