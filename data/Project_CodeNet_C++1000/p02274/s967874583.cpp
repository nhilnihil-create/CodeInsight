#include <stdio.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define INF 3333333333
#define uint unsigned int
#define llong long long

llong merge(uint S[], int left, int mid, int right) {
  llong numInv = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  uint L[n1 + 1], R[n2 + 1];
  REP(i, n1) {
    L[i] = S[left + i];
  }
  REP(i, n2) {
    R[i] = S[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;

  int i = 0, j = 0;
  FOR(k, left, right) {
    if(L[i] <= R[j]) {
      S[k] = L[i];
      i += 1;
    } else {
      S[k] = R[j];
      j += 1;
      numInv += n1 - i;
    }
  }
  return numInv;
}

llong mergeSort(uint S[], int left, int right) {
  llong numInv = 0, mid;
  if((left + 1) < right) {
    mid = (left + right) / 2;
    numInv += mergeSort(S, left, mid);
    numInv += mergeSort(S, mid, right);
    numInv += merge(S, left, mid, right);
  }
  return numInv;
}

int main(void) {
  int n;
  scanf("%d", &n);
  uint S[n];
  REP(i, n) {
    scanf("%d", &S[i]);
  }

  llong numInv = mergeSort(S, 0, n);

  printf("%lld\n", numInv);

  return 0;
}