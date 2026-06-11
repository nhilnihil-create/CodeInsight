#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(){

  int x[10000]={0};
  int y[10000]={0};
  double d1=0,d2=0,d3=0,d4=0;
  int n=0;
  int i;

  cin >>n;

  for(i=0;i<n;i++){
    cin >>x[i];
  }
  for(i=0;i<n;i++){
    cin >>y[i];
  }

  //p=1
  for(i=0;i<n;i++){
    d1+=fabs(x[i]-y[i]);
  }
  cout <<fixed <<d1 <<endl;

  //p=2
  for(i=0;i<n;i++){
    d2+=fabs(x[i]-y[i])*fabs(x[i]-y[i]);
  }
  d2=sqrt(d2);
  cout <<fixed <<d2 <<endl;

  //p=3
  for(i=0;i<n;i++){
    d3+=fabs(x[i]-y[i])*fabs(x[i]-y[i])*fabs(x[i]-y[i]);
  }
  d3=pow(d3,1.0/3.0);
  cout <<fixed <<d3 <<endl;

  //p=???
  for(i=0;i<n;i++){
    if(fabs(x[i]-y[i])>d4) d4=fabs(x[i]-y[i]);
  }
  cout <<fixed <<d4 <<endl;


  return 0;
}