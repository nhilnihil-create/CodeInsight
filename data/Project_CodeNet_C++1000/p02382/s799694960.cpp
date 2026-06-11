#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  int n;
  cin >> n;

  double* X = new double[n];
  double* Y = new double[n];
  double p_1=0,p_2=0,p_3=0,p_inf=0;

  for(int i=0;i<n;i++) cin >> X[i];
  for(int i=0;i<n;i++) cin >> Y[i];

  for(int i=0;i<n;i++){
    int x_y = abs(X[i] - Y[i]);
    p_1 += x_y;
    p_2 += x_y * x_y;
    p_3 += x_y * x_y * x_y;
    p_inf = (p_inf > x_y) ? p_inf : x_y;
  }
  p_2 = sqrt(p_2);
  p_3 = cbrt(p_3);

  delete[] X;
  delete[] Y;

  cout << setprecision(12) << p_1 << endl;
  cout << p_2 << endl;
  cout << p_3 << endl;
  cout << p_inf << endl;
}
