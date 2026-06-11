#include <bits/stdc++.h>

int main() {

  double sum = 0;
  double sum2 = 0;
  double input;
  int N;


  for(;;) {
    std::cin >> N;
    if( N == 0 ) {
      break;
    }
    
    sum = sum2 = 0;
    for(int i = 0; i < N; ++i) {
      std::cin >> input;
      sum += input;
      sum2 += input*input;
    }
    printf("%.10lf\n", sqrt(sum2/N - (sum/N)*(sum/N)));
  }
  
  return 0;
}