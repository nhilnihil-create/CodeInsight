#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
 while(1){
  int n;
  cin >> n;
  if(n == 0) break;
  int s[n];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += s[i];
  }
  double mean = 1.0 * sum / n;
  double var = 0.0;
  for(int i = 0; i < n; i++){
    var += 1.0 * (s[i] - mean) * (s[i] - mean);
   }
  double SD = sqrt(1.0 * var / n);
  printf("%f\n", SD);
  }
 return 0;
}
