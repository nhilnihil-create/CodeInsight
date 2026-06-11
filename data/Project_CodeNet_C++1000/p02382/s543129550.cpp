#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int x[n], y[n];
  double D[4]={};
  for(int i=0;i<n;i++)
    cin >> x[i];
  for(int i=0;i<n;i++)
    cin >> y[i];
  D[0] = fabs(x[0]-y[0]);
  for(int i=0;i<n;i++)
    {
      D[1] += abs(x[i]-y[i]);
      D[2] += (x[i]-y[i])*(x[i]-y[i]);
      D[3] += fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
      fabs(x[i]-y[i]) >= D[0] ? ( D[0] = fabs(x[i]-y[i]) ):(0);
    }
  D[2] = sqrt(D[2]);
  D[3] = pow(D[3], (double)1/3);

  cout << fixed << setprecision(6)
       << D[1] << endl
       << D[2] << endl
       << D[3] << endl
       << D[0] << endl;
}