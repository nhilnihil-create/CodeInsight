#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#define MAXSIZE 101
#define PI 3.141592653589
using namespace std;
int main(){
  int n;

  int num[1000]={0};

  while (1) {
    std::cin >> n;
    if(0==n)break;
    long long int sum=0;
    for(int i=0;i<n;i++){
      std::cin >> num[i];
      sum+=num[i];
    }

    double ave=(double)sum/n;
    double a2before=0;
    for(int i=0;i<n;i++){
      a2before+=(num[i]-ave)*(num[i]-ave);
    }
    double a2=a2before/n;

    printf("%.8f\n",sqrt(a2));
  }

}