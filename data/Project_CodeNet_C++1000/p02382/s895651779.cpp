//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_D
#include <iostream>
#include <cstdio>
#include <cmath>

const double inf = 100;

using namespace std;
int main(){
  int n;
  cin >> n;
  double x[n],y[n];
  for(int i =0; i<n;i++){
    cin >> x[i];
  }
  for(int i =0; i<n;i++){
    cin >> y[i];
  }

  double in;
  for(int i = 1; i<5; i++){
    double sum = 0;
    double distance = 0;
    if(i == 4){
      int max = abs(x[0] - y[0]);
      for(int j=0;j<n;j++){
        if(max < abs(x[j]-y[j])) max = abs(x[j]-y[j]);
      }
      distance = pow(max, inf);
      distance = pow(distance, 1.0/inf);
      }
    else{
      for(int j=0;j<n;j++){
        sum += pow(abs(x[j]- y[j]), i);
        }
      in = 1/double(i);
      distance = pow(sum, in);
      }
    printf("%.6lf\n", distance);
    }
}