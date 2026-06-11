#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main(){
  double n, s[1010], sd;
  while(cin>>n && n != 0){
    double sum = 0, double_sum = 0, m;
    for(int i=0;i<n;i++){
      cin>>s[i];
      sum += s[i];
      double_sum += pow(s[i], 2);
    }
    m = sum / n;
    sd = sqrt(double_sum / n - pow(m, 2));
    printf("%.5f\n", sd);
  }
  return 0;
}

