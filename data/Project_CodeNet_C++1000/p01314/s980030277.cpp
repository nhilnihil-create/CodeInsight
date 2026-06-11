#include <cstdio>

int main() {
  int N;
  while (true) {
    scanf("%d", &N);
    if (N == 0) break;
    int cnt = 0;
    for (int i=0;i<N;i++) {
      for (int j=i+2;j<=N;j++) {
        if (j*(j+1)/2 - i*(i+1)/2 == N) cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}