#include <cstdio>
#include <cmath>

int main(){
  int vecx[100], vecy[100];
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; i++)scanf("%d", &vecx[i]);
  for(int i = 0; i < n; i++)scanf("%d", &vecy[i]);

  double d[4];
  for( int i = 0; i < 4; i++) d[i] = 0.0;

  for (int p = 1; p < 4; p++ ){
    for ( int i = 0; i < n; i++ ){
      d[p] += pow(fabs(vecx[i]-vecy[i]), p);
    }
    d[p] = pow(d[p], 1.0/p);
  }

  for ( int i = 0; i < n; i++ ){
    d[0] = (d[0] < fabs(vecx[i]-vecy[i])?fabs(vecx[i]-vecy[i]):d[0]);
  }

  printf("%lf\n", d[1]);
  printf("%lf\n", d[2]);
  printf("%lf\n", d[3]);
  printf("%lf\n", d[0]);

  return 0;
}