#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(){
  int i ,n;
  
  while(cin >> n){
    double hensa=0,sum=0;
    double sum2=0,bunsan=0;
    if (n ==0)break;
    int score[n];
    for ( i = 0 ; i < n ; i++){
      cin >> score[i];
      sum += score[i];
    }
    double ave = sum / n;
    for ( i = 0 ; i < n ; i++){
      bunsan = pow(score[i]-ave,2);
      sum2 += bunsan;
      bunsan = 0;
    }
    sum2 = sum2/n;
    hensa = sqrt(sum2);
    printf("%.8f\n",hensa);
  }
  return 0;
}