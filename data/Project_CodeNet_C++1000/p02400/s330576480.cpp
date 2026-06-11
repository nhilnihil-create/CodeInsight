#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  double r;
  fscanf(stdin, "%lf", &r);
  double area = M_PI * r * r;
  double circum = 2.0 * M_PI * r;
  fprintf(stdout, "%f %f", area, circum);
  fprintf(stdout, "\n");
  return 0;
}