#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
  int n,k,m,j;
  double x[1001], y[1001], z[5];

  cin >> n;
  for(k = 1; k <= n; k++){
    cin >> x[k];
  }
  for(k = 1; k <= n; k++){
    cin >> y[k];
  }
  for(m = 1; m <= 4; m++){
    z[m] = 0;
    for(k = 1; k <= n; k++){
      j = m;
      if(j != 4)
        z[m]=z[m]+pow(abs(x[k]-y[k]),j);
      else
        {j=1; z[m]=max(z[m],abs(x[k]-y[k]));}
    }
    z[m]=pow(z[m],1.0/j);
    cout << fixed << setprecision(6) << z[m] << endl;
  }     
  return 0;
}