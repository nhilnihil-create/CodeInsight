#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main() {

  for (;;) {
  
    int n;
    cin >> n;

    if (n == 0) break;
    
    int s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    
    double m = 0, total = 0;
    for (int i = 0; i < n; i++) {
      total += s[i];
    }
    m = total / (double)n;
    
    double a2 = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += pow(s[i]-m,2);
    }
    a2 = sum / (double)n;
    
    printf("%.5f\n",sqrt(a2));
    
  }
  
  return 0;
}

