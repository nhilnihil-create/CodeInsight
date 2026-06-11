#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, s[1001];
double sum = 0, m = 0, d_sum = 0, d = 0, sd = 0;


int main(){
  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++){
      cin >> s[i];
      sum += s[i];
    }
    m = sum/n;
    sum = 0;

    for(int i = 0; i < n; i++){
      d_sum += pow(s[i] - m, 2);
    }
    sd = sqrt(d_sum / n);
    printf("%.8f\n", sd);
    d_sum = 0;
  }
}