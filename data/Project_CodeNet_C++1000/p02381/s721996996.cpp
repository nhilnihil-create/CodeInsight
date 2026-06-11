#include<iostream>
#include<stdio.h>
#include<math.h>

int main(){
  while(true){
    int n;
    std::cin >> n;
    if(n == 0) break;

    int s[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
      std::cin >> s[i];
      sum += s[i];
    }
    double m = (double)sum / n;
    double v = 0;
    for(int i = 0; i < n; i++){
      v += (m - s[i]) * (m - s[i]);
    }
    double sd = sqrt(v / n);
    printf("%f\n", sd);
  }

  return 0;
}

