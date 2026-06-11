#include <cstdio>
#include <cmath>

int main(){
  while(1){
    int n;
    scanf("%d", &n);
    if(n == 0) break;
    int points[n];
    for ( int i = 0; i < n; i++ ){
      scanf( "%d", &points[i] );
    }
    int sum = 0;
    for (int i = 0; i < n ; i++ ){
      sum += points[i];
    }
    double avg;
    avg = 1.0*sum / n;
    double devpoints[n];
    for (int i = 0; i < n; i++ ){
      devpoints[i] = (points[i] - avg)*(points[i] - avg);
    }
    double a2 = 0.0;
    for ( int i = 0; i < n; i++ ){
      a2 += devpoints[i];
    }
    double a;
    a = sqrt(a2/n);


    printf("%lf\n", a);
  }
  return 0;
}