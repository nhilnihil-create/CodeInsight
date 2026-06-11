#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int x[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  int y[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &y[i]);
  }

  double D[4] = {};
  for (int i = 0; i < n; i++) {
    D[0] += abs(x[i] - y[i]);
  }

  for (int i = 0; i < n; i++) {
    int xy = abs(x[i] - y[i]);
    D[1] += xy * xy;
  }
  D[1] = sqrt(D[1]);

  for (int i = 0; i < n; i++) {
    int xy = abs(x[i] - y[i]);
    D[2] += xy * xy * xy;
  }
  D[2] = cbrt(D[2]);

  for (int i = 0; i < n; i++) {
    if (abs(x[i] - y[i]) > D[3]) {
      D[3] = abs(x[i] - y[i]);
    }
  }

  printf("%f\n%f\n%f\n%f\n", D[0], D[1], D[2], D[3]);

  return 0;
}
