#include <bits/stdc++.h>
using namespace std;

#define N (123456*2)

int n;
bool is_composite[N+1];
int num[N+1];

int main() {
  for (int i=2; i<=N; i++) {
    num[i] = num[i-1];
    if (!is_composite[i]) {
      num[i]++;
      for (int j=i+i; j<=N; j+=i) {
        is_composite[j] = true;
      }
    }
  }

  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;

    printf("%d\n", num[n*2]-num[n]);
  }
}