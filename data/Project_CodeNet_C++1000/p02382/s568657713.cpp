#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
 int n;
 cin >> n;
 int x[n], y[n];
 for(int i = 0; i < n; i++){
   cin >> x[i];
  }
 for(int i = 0; i < n; i++){
   cin >> y[i];
  }

 double D_1 = 0.0;
 for(int i = 0; i < n; i++){
   D_1 += 1.0 * abs(x[i] - y[i]);
 }
 printf("%f\n", D_1);

 double D_2 = 0.0;
 for(int i = 0; i < n; i++){
   D_2 += 1.0 * pow(x[i] - y[i], 2);
 }
 printf("%f\n", sqrt(D_2));

 double D_3 = 0.0;
 for(int i = 0; i < n; i++){
   D_3 += 1.0 * abs( pow(x[i] - y[i], 3.0) );
 }
 printf("%f\n", pow(D_3, 1.0 / 3.0));

 double D_4 = 0.0;
 for(int i = 0; i < n; i++){
   if(abs(x[i] - y[i]) > D_4) D_4 = abs(x[i] - y[i]);
 }
 printf("%f\n", D_4);
}
 
