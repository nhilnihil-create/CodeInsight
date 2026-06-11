#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
  double n, x[100], y[100], sum1, sum2, sum3, max = 0;

  cin >> n;
  for(int i = 0; i < n; i++){ cin >> x[i];}
  for(int i = 0; i < n; i++){ cin >> y[i];}

  for(int i = 0; i < n; i++){
    sum1 += fabs(x[i] - y[i]);
    sum2 += pow(x[i] - y[i], 2);
    sum3 += pow(fabs(x[i] - y[i]), 3);
    max = fabs(x[i] - y[i]) > max ? fabs(x[i] - y[i]) : max;
  }
  cout
    << fixed << setprecision(6)
    << sum1 << endl
    << sqrt(sum2) << endl
    << pow(sum3, 1.0 / 3.0) << endl
    << max << endl;
}