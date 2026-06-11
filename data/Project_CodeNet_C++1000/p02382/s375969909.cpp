#include<cstdio>
#include<cmath>

int main(){
  int n;
  int x[100] = {};
  int y[100] = {};
  double z[100] = {};
  double p1 = 0, p2 = 0, p3 = 0, pp = 0;
  scanf("%d", &n);

  for( int i = 0; i < n; i++ ){
    scanf("%d", &x[i]);
  }

  for( int i = 0; i < n; i++ ){
    scanf("%d", &y[i]);
  }

  for( int i = 0; i < n; i++ ){
    z[i] = fabs( x[i] - y[i] );
  }

  for( int i = 0; i < n; i++ ){
    p1 += z[i];
    p2 += pow(z[i],2);
    p3 += pow(z[i],3);
    if( z[i] > pp ) pp = z[i];
  }

  printf("%f\n%f\n%f\n%f\n", p1, sqrt(p2), pow(p3, 1.0 / 3.0), pp);

  return 0;
}