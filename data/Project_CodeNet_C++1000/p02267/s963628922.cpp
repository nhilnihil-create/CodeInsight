#include <cstdio>

bool isInArray(int x, int array[], int size) {
  for(int i = 0; i < size; i++) {
    if(x == array[i]) {
      return true;
    }
  }
  return false;
}


int main(void) {
  int n, q;
  int num;

  scanf("%d", &n);
  int S[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  int x;
  num = 0;
  for(int i = 0; i < q; i++) {
    scanf("%d", &x);
    if(isInArray(x, S, n)) {
      num++;
    }
  }

  printf("%d\n", num);
  return 0;
}