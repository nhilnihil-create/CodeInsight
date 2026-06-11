#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int i;

  while( 1 ){
    int n, s[1000] = {};
    double sd = 0, avg = 0, disp = 0;
    // ?¨?????????? standard deviation, ?????£ dispersion
    cin >> n;
    if( n == 0 ) break;
    
    for( i = 0; i < n; i++ ){
      cin >> s[i];
      avg += s[i];
    }
    avg = avg / n;

    for( i = 0; i < n; i++ ){
      disp += ( s[i] - avg )*( s[i] - avg );
    }

    printf("%lf\n", sqrt( disp / n ));
  }
  
  return 0;
}