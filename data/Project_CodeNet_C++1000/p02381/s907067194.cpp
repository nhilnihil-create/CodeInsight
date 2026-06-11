#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
  int n;
  int score[1000];
  double stdev;

  double a;

  while(true){
    double sum1=0, sum2=0, ave=0;

    cin>>n;
    if(n==0){
      break;
    }else{
      for(int i=0; i<n; ++i){
        cin>>score[i];
        sum1 = sum1 + score[i];
      }
      ave =sum1/n;
      for(int i=0; i<n; ++i){
        a = score[i] - ave;
        a = a * a;
        sum2 = sum2 + a;
      }
      stdev = sum2/n;
      stdev = sqrt(stdev);
    }
    printf("%.15lf\n", stdev);
  }
}