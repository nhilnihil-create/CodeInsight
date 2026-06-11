#include <cstdio>
#include <cstring>
using namespace std;

const int N = 123456*2;
bool prime[N+1];
int sum[N+1];

int main() {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int i = 2; i*i <= N; ++i) {
    if (prime[i]) {
      for (int j = i*i; j <= N; j += i) { prime[j] = false; }
    }
  }
  sum[0] = 0;
  for (int i = 1; i <= N; ++i) {
    sum[i] += prime[i] + sum[i-1];
  }

  int n;
  while (scanf("%d", &n), n) {
    printf("%d\n", sum[2*n] - sum[n]);
  }
}