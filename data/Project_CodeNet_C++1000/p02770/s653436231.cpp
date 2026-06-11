#include <cstdio>

using namespace std;

int main()
{
  int k, q;
  int d[5000];
  
  scanf("%d %d", &k, &q);
  
  for (int i = 0; i < k; i++) scanf("%d", d + i);
  
  for (int i = 0; i < q; i++) {
    int n, x, m;
    scanf("%d %d %d", &n, &x, &m);
    long long dif = x % m;
    for (int j = 0; j < k; j++) {
      long long M = (d[j] % m == 0 ? m : d[j] % m);
      dif += M * ((n - 1) / k + (j < (n - 1) % k));
    }
    printf("%d\n", n - 1 - dif / m);
  }
  return 0;
}