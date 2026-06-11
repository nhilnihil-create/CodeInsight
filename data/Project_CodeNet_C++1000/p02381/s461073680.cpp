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

  while(true){
    
    cin >> n;
    if(n == 0 )break;
  
    int x[n];
  
    double sum = 0;
    for(int i=0;i<n;i++){
      cin >> x[i];
      sum += x[i];
    }

    double ave = sum/n;

    double y =0;
    for(int i=0;i<n;i++){
      y += pow((x[i]-ave),2);

    }
    cout << setprecision(15) << sqrt(y/n) << endl;


    
  }
  



}



