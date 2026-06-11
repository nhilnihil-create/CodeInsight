#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define PI 3.14159265358979

using namespace std;

int main(){
  int n;
  cin >> n;
  double x[n],y[n];
  for(int i=0;i < n;i++){
    cin >> x[i];
  }
  for(int i=0;i < n;i++){
    cin >> y[i];
  }
  double dist1 = 0,dist2 = 0,dist3 = 0,dist_inf = 0;

  //n = 1
  for(int i=0;i < n;i++){
    dist1 += abs(x[i] - y[i]);
  }

  //n = 2
  for(int i=0;i < n;i++){
    dist2 += (x[i] - y[i])*(x[i] - y[i]);
  }
  dist2 = sqrt(dist2);

  //n = 3
  for(int i=0;i < n;i++){
    dist3 += abs((x[i] - y[i])*(x[i] - y[i])*(x[i] - y[i]));
  }
  dist3 = cbrt(dist3);

  //n = ∞
  for(int i=0;i < n;i++){
    dist_inf = max(dist_inf,abs(x[i] - y[i]));
  }
  printf("%.8lf\n",dist1);
  printf("%.8lf\n",dist2);
  printf("%.8lf\n",dist3);
  printf("%.8lf\n",dist_inf);
  
  return 0;
}
