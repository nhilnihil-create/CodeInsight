#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {

  int i , n;

  double a , m , total , s[1001] = {};

  while(1) {

    cin >> n;

    if(n == 0) break;

    s[1000] = total = 0;

    for(i = 0; i < n; i++) {

      cin >> s[i];

      s[1000] += s[i];

    }

    m = s[1000] / n;

    for(i = 0; i < n; i++) {

      total += pow(s[i] - m , 2);

    }

    a = sqrt(total / n);

    printf("%.8lf\n",a);

  }

  return 0;

}