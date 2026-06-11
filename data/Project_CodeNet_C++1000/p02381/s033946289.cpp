#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
  vector<int> v(1024,0);
  int i,n,sum;
  double a=0;
  
  while( cin >> n, n != 0 ){
    for(i=0;i<n;i++){
      cin >> v[i];
      sum += v[i];
    }

    double m = (double)sum / (double)n;
    
    for(i=0;i<n;i++){
      a += pow((v[i]-m),2)/n;
    }
    printf("%.8f\n",sqrt(a));
    a=0;
    sum = 0;
    v.erase(v.begin(),v.end());
  }

  return 0;
}