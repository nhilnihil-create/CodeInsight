#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>x(N);
  vector<int>y(N);
  vector<double>out(4);

  for(int i=0;i<N;i++){
    cin >> x[i];
  }
  for(int i=0;i<N;i++){
    cin >> y[i];
  }
  for(int i=0;i<3;i++){
    double sum = 0;
    for(int j=0;j<N;j++){
      sum += pow(abs(x[j]-y[j]), i+1);
    }
    out[i] = pow(sum, 1.0 / (i+1));
  }
  int val=0;
  for(int i=0;i<N;i++){
    val = max(val, abs(x[i] - y[i]));
    out[3] = val;
  }

  for(int i=0;i<4;i++){
    printf("%.10lf\n", out[i]);
  }


  return 0;
}