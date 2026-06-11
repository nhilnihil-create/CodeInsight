#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  while (1) {
    long long n, sum = 0, s[1001];
    double sum2 = 0;

    cin >> n;
    if (n == 0) break;

    for (int i = 1; i <= n; i++){
      cin >> s[i];
      sum += s[i];
    }
    double m = (double)sum / n;

    for (int i = 1 ; i <= n; i++){
       sum2 += (s[i]-m)*(s[i]-m);
    }
    double a2 = (double)sum2 / n;

    printf("%lf\n", sqrt(a2));


  }

return 0;
}