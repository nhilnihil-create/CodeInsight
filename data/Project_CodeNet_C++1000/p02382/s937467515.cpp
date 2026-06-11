#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;
 
int main()
{
  int n, *x, *y;
  double d_man, d_euc, d_cub, d_che;

  cin >> n;
  x = new int [n];
  y = new int [n];
  
  for(int i=0; i<n; i++){
    cin >> x[i];
  }
  for(int i=0; i<n; i++){
    cin >> y[i];
  }
  
  int dif;
  d_man = d_euc = d_cub = d_che = 0;
  for(int i=0; i<n; i++){
    dif = abs(x[i] - y[i]);
    d_man += dif;
    d_euc += pow(dif, 2.0);
    d_cub += pow(dif, 3.0);
    if(d_che < dif){
      d_che = dif;
    }
  }

  d_euc = sqrt(d_euc);
  d_cub = pow(d_cub, 1./3);
  
  cout << fixed
    << setprecision(5)
      << d_man << endl
        << d_euc << endl
          << d_cub << endl
            << d_che << endl;

  return(0);
}