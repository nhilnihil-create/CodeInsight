#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  int a, b;
  fscanf(stdin, "%d %d", &a, &b);
  int d = a / b, r = a % b;
  double f = a * 1.0 / b;
  fprintf(stdout, "%d %d %f", d, r, f);
  fprintf(stdout, "\n");
  return 0;
}