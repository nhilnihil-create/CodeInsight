#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

double cal(vector<int> x, vector<int> y, int p)
{
  double ret = 0;
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    ret += pow(abs(x[i] - y[i]), p);
  }
  ret = pow(ret, 1.0 / p);
  return ret;
}

int main()
{
  int n = 0;
  fscanf(stdin, "%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    fscanf(stdin, "%d", &x[i]);
  }
  for (int i = 0; i < n; ++i) {
    fscanf(stdin, "%d", &y[i]);
  }
  double chev = -1;
  for (int i = 0; i < n; ++i) {
    chev = max(chev, 1.0 * abs(x[i] - y[i]));
  }
  double man = cal(x, y, 1);
  double euc = cal(x, y, 2);
  double tri = cal(x, y, 3);
  fprintf(stdout, "%.8lf\n", man);
  fprintf(stdout, "%.8lf\n", euc);
  fprintf(stdout, "%.8lf\n", tri);
  fprintf(stdout, "%.8lf\n", chev);
  return 0;
}