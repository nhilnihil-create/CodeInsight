#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  int n;

  for(;;){
    cin >> n;
    if ( n == 0 ) break;

    double scores[1000] ={}, sum = 0;
    double m = 0, sigma = 0, stddev = 0;

    for (int i=0; i<n; i++){
      cin >> scores[i];
      sum += scores[i];
    }
    m = sum / n;

    for ( int i=0; i<n; i++){
      sigma += pow(scores[i] - m, 2);
    }
    stddev = sqrt(sigma/n);

    printf("%lf\n", stddev);
  }

  return 0;
}