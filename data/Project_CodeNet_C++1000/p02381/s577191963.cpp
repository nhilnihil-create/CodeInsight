#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void)
{
  int n,k,m;
  double a[1001], sum1, sum2, av, sg[1001];

  n = 1;
  m = 0;
  while(n > 0) {
    m = m + 1;
    cin >> n;
    sum1 = 0;
    sum2 = 0;
    for(k = 1; k <= n; k++){
      cin >> a[k];
      sum1 = sum1 + a[k];
      sum2 = sum2 + a[k]*a[k];
    }
    av = sum1/n;
    sg[m] = sqrt(sum2/n - av*av);
  }

  for(k = 1; k < m; k++){
    cout << fixed << setprecision(6) << sg[k] << endl;
  }     
  return 0;
}