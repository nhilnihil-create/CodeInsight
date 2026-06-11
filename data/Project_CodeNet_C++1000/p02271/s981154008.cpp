#include <iostream>
#include <algorithm> //sort
#include <stdio.h>   //printf

using namespace std;

static const int MAX_ELEMENT = 20;

/*
int rec(int idx, int n, int *A){
  int i;
  if (idx >= n) {
    printf("{%d", A[0]);
    for (i = 1; i < n; i++)
      printf(", %d", A[i]);
    printf("}\n");
    return;
  }

  A[idx] = 0;
  rec(idx+1, n, A);

  A[idx] = 1;
  rec(idx+1, n, A);
}

void makeConbination(int n) {
  int i, *S;
  S = new int[n];

  S[0] = 0;
  rec(1, n, S);

  S[0] = 1;
  rec(1, n, S);

  delete[] S;
}
*/

int solve(int *A, int idx, int n, int m) {
  int res;

  if (m == 0) return 1;
  if (idx >= n) return 0;

  res = solve(A, idx+1, n, m) || solve(A, idx+1, n, m - A[idx]);

  return res;
}

int main(){
  int i, j, n, q, m, A[MAX_ELEMENT] = {0};

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  //??????????????????
  sort(A, A+n);

  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> m;

    //A?????´???????????¨?????????
    for (j = 0; j < n; j++) {
      if (A[j] > m)
        break;
    }
    //A[0] ~ A[j]???????´??????¨????????????????????????????????????
    if ( solve(A, 0, j, m) )
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}