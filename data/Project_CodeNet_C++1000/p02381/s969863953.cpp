#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
 

int main(){

  int n,sum;
  int val[1000];
  double a;
  
  while(1){
    cin >> n;
    if(n==0) break;
    
    sum=0; a=0;
    
    for(int i=0; i<n; i++){
      cin >> val[i];
      sum += val[i];
    }
    for(int i=0; i<n; i++){
      a += (val[i]-(double)sum/n)*(val[i]-(double)sum/n);
    }
    
    a /= (double)n;

  
    printf("%.8lf\n",sqrt(a));
    
  }
  
  return 0;
}