#include <stdio.h>
#include <math.h>

double d_minkowski_k(int *d, int n, double k);
double d_chebyshev(int *d, int n);

int main(void)
{
  int i,n, x[100],y[100],d[100];
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    scanf("%d", &x[i]);
  }
  for(i=0;i<n;i++) {
    scanf("%d", &y[i]);
    d[i]= fabs(x[i]-y[i]);
  }
  printf("%lf\n", d_minkowski_k(d,n,1));
  printf("%lf\n", d_minkowski_k(d,n,2));
  printf("%lf\n", d_minkowski_k(d,n,3));
  printf("%lf\n", d_chebyshev(d, n));
  return 0;
}

double d_minkowski_k(int *d, int n, double k)
{
  double distance=0;
  int i;
  for(i=0;i<n;i++) {
    distance += pow(d[i], k);
  }
  return pow(distance, 1/k);
}

double d_chebyshev(int *d, int n)
{
  double max=0;
  int i;
  for(i=0;i<n;i++) {
    if(max<d[i])
      max=d[i];
  }
  return max;
}