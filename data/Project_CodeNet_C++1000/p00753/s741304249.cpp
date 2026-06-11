#include<cstdio>
using namespace std;

int prime[1000];
int primeNumber = 0;

int main() {
  for (int i = 2; i <= 1000; i++) {
    bool flag = true;
    for (int j = 0; j < primeNumber; j++) if (i % prime[j] == 0) flag = false, j = primeNumber;
    if (flag) prime[primeNumber++] = i;
  }
  int n, counter;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    counter = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
      bool flag = true;
      for (int j = 0; prime[j] * prime[j] <= i; j++) if (i % prime[j] == 0) {
        flag = false;
        break;
      }
      if (flag) counter++;
    }
    printf("%d\n", counter);
  }
}

