#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int n,s[1000] = {0};
  int sum = 0;
  
  while (1) {
    cin >> n;
    if ( n == 0 ) {
      putchar ('\n');
      break;
    }
    sum = 0; //crucial!
    for ( int i = 0; i < n; i++ ) {
      cin >> s[i];
      sum += s[i];
    }
    double m = (double)sum / n;
    double subvar = 0;
    for ( int i = 0; i < n; i++ ) {
      subvar += pow(s[i] - m, 2);
    }
    double var = subvar / n;
    double StDv = sqrt(var); //standard deviation
    printf ("%lf\n",StDv);
  }
  
  return 0;
}
