#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
  double x[1000];
  double y[1000];
  int n;
  cin >>n;
  for (int i = 0; i < n ; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n ; i++) {
    cin >> y[i];
  }
  double p1 = 0;
  for (int i = 0; i < n ; i++) {
    p1 += abs(x[i] - y[i]);
  }
  
  double p2 = 0;
  for (int i = 0; i < n ; i++) {
    p2 += pow(abs(x[i] - y[i]), 2);
  }
  p2 = sqrt(p2);

  double p3 = 0;
  for (int i = 0; i < n ; i++) {
    p3 += pow(abs(x[i] - y[i]), 3);
  }
  p3 = pow(p3, 1.0 / 3.0);

  double pinf = 0;
  double xy[1000];
  for(int i = 0; i < n ; i++) {
    double now = abs(x[i] - y[i]);
    if (pinf < now) {
        pinf = now;
    }
  }

  printf("%.5f\n", p1);
  printf("%.5f\n", p2);
  printf("%.5f\n", p3);
  printf("%.5f\n", pinf);
}