#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
  while(1){
  int n;
  cin>>n;
  if(n==0) break;
  int s[n];
  int sum = 0;
  double average,dev2=0.0;
  for(int i=0;i<n;i++){
    cin>>s[i];
    sum+=s[i];
  }
  average = (double)sum / n ;
  for(int i=0;i<n;i++){
    dev2 += (s[i]-average)*(s[i]-average);
  }
  printf("%.10lf\n",sqrt(dev2/n));
  }
  return 0;
}