#include <stdio.h>
#include <string.h>

const char* echo(int N, char* S) {
  if(N % 2 == 1) {
    return "No";
  }

  for(int i=0; i < N/2 ;i++){
        if(S[i] != S[i + N/2]){
            return "No";
        }
    }

  return "Yes";
}

int main() {
    int N;
    char S[102];
    scanf("%d %s", &N, S);
  printf("%s\n", echo(N, S));

  return 0;
}