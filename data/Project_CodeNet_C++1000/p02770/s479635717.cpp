#include<cstdio>

int k, q;
int d[5003];

int main() {
  scanf("%d %d", &k, &q);
  for (int i = 0; i < k; i++) {
    scanf("%d", &d[i]);
  }
  for (int i = 0; i < q; i++) {
    int n, x, m;
    scanf("%d %d %d", &n, &x, &m);
    x %= m;
    long long sum = 0;
    int cz = 0;
    for (int j = 0; j < k; j++) {
      sum += d[j] % m;
      if (d[j] % m == 0) {
        ++cz;
      }
    }
    sum *= (n - 1) / k;
    cz *= (n - 1) / k;
    for (int j = 0; j < (n - 1) % k; j++) {
      sum += d[j] % m;
      if (d[j] % m == 0) {
        ++cz;
      }
    }
    sum += x;
    printf("%lld\n", n - cz - sum / m - 1);
  }
}
