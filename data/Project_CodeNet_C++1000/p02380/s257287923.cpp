#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  int a, b, c;
  fscanf(stdin, "%d %d %d", &a, &b, &c);
  double theta =  c * M_PI / 180.0;
  double S = 0.5 * a * b * sin(theta);
  double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(theta));
  double h = b * sin(theta);
  fprintf(stdout, "%f\n", S);
  fprintf(stdout, "%f\n", L);
  fprintf(stdout, "%f\n", h);
  return 0;
}