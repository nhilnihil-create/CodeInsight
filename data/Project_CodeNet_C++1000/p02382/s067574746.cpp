#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n, i, x[1000] = {0}, y[1000] = {0};
  double d1 = 0, d2 = 0, d3 = 0, D2, D3, max;

  cin >> n;
  for(i = 0; i < n; i++) cin >> x[i];
  for(i = 0; i < n; i++) cin >> y[i];
  for(i = 0; i < n; i++){
    d1 += fabs(x[i] - y[i]);
    d2 += pow(fabs(x[i] - y[i]), 2.0);
    d3 += pow(fabs(x[i] - y[i]), 3.0);
    if(max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
  }
  D2 = sqrt(d2);
  D3 = pow(d3, 1.0/3.0);
  cout << fixed << d1 << endl;
  cout << D2 << endl;
  cout << D3 << endl;
  cout << max << endl;

  return 0;
}