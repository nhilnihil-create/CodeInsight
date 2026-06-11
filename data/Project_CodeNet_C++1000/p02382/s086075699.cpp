#include<iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
int main(){

  static int n;
  
  cin >> n;
  
  int x[n];
  int y[n];

  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  for(int i=0;i<n;i++){
    cin >> y[i];
  }

  double sum = 0;
  for(int i=0;i<n;i++){
    sum += abs(x[i]-y[i]);
  }
  cout << setprecision(15) << sum << endl;

  sum=0;
  for(int i=0;i<n;i++){
    sum += pow(abs(x[i]-y[i]),2);
  }
  cout << setprecision(15) << sqrt(sum) << endl;

  sum=0;
  for(int i=0;i<n;i++){
    sum += pow(abs(x[i]-y[i]),3);
  }
  cout << setprecision(15) << cbrt(sum) << endl;

  int maxi =0;
  for(int i=0;i<n;i++){
    maxi =  max(maxi, abs(x[i]-y[i]) );
  }
  cout << setprecision(15) << maxi << endl;


}



