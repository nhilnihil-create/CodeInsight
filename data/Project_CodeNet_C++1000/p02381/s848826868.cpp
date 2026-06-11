#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  while(1){
    int n, m1 = 0;
    double s1 = 0;
    int b[1001] = {};

    cin >> n;
    if( n == 0 ) break;
 
    for( int i = 0; i < n; i++ ){
      int s;
      cin >> s;
      b[i] = s;
      m1 += s;
    }
 
    double m2 = (double)m1 / n;

    for( int i = 0; i < n; i++ ){
      s1 += pow(b[i] - m2,2);
    }

    double a = sqrt( s1 / n );
    
    printf("%f\n", a);
  }

  return 0;
}