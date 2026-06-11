#include <iostream>
#include <cstdio>
#include <cmath>

int main(){
  int n;
  double s[1000];


  while(true){
    std::cin >> n;
    if(n==0) break;

    double sum=0, mean=0, var=0;

    for(int i=0; i<n; i++){
      std::cin >> s[i];
      sum += s[i];
    }

    mean = sum / n;

    for(int i=0; i<n; i++){
      var += (s[i] - mean)*(s[i] - mean);
    }
    var = var / n;

    printf("%.8lf\n", sqrt(var));
  }
}

