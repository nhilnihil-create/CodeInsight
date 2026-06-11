#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  int n;
  while(true)
  {
    cin >> n;
    if (n == 0) return 0;
    int* s = new int[n];

    for (int i=0; i<n; i++)
    {
      cin >> s[i];
    }

    double avg;
    int sum = 0;
    for (int i=0; i<n; i++)
    {
      sum += s[i];
    }
    avg = sum / (double)n;

    double sigma = 0.0;
    for (int i=0; i<n; i++)
    {
      sigma += (s[i]-avg)*(s[i]-avg);
    }
    delete[] s;

    double alpha = sqrt( sigma/(double)n );

    printf("%.8lf\n", alpha);
  }
}