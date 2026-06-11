#include<iostream>
#include<cmath>
using namespace std;

int main(){

  int n;
  int i;
  double D_1 = 0;
  double D_2 = 0;
  double D_3 = 0;
  double D_i = 0;
  cin >> n;

  int x[100];
  int y[100];

  for(i = 0;i < n;i++){
    cin >> x[i];
  }
  for(i = 0;i < n;i++){
    cin >> y[i];
  }

  for(i = 0;i < n;i++){
    D_1 += abs(x[i] - y[i]);
    D_2 += pow(abs(x[i] - y[i]),2);
    D_3 += pow(abs(x[i] - y[i]),3);
    D_i = max((double)abs(x[i] - y[i]),D_i);
  }

  D_2 = sqrt(D_2);
  D_3 = pow(D_3,(double)1/3);

  cout << fixed <<  D_1 << endl << D_2 << endl << D_3 << endl << D_i << endl;

  return 0;
}