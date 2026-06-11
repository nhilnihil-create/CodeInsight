#include <stdio.h>

bool echo(int N, char S[]) {
  for(int i = 0; i < N/2; i++) {
    if(S[i] != S[i + N/2]) {
      return false;
    }
  }

  return true;
}

int main() {
  int N;
  char S[102];
  scanf("%d %s", &N, S);
  (N % 2 == 0 && echo(N, S)) ? puts("Yes") : puts("No");
  
  return 0;
}