#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  while (true) {
    int n;
    fscanf(stdin, "%d", &n);
    if (n == 0) { break; }
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      fscanf(stdin, "%d", &v[i]);
      sum += v[i];
    }
    double mean = sum * 1.0 / n;
    double alpha = 0;
    for (int i = 0; i < n; ++i) {
      alpha += (v[i] - mean) * (v[i] - mean);
    }
    alpha /= n;
    fprintf(stdout, "%.9f\n", sqrt(alpha));
  }
  return 0;
}