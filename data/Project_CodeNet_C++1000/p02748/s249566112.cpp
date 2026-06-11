#include <iostream>
#include <stdio.h>

#define MAX_A 100'000

using namespace std;

int A[MAX_A];
int B[MAX_A];

int main() {
  int NA, NB, M;
  cin >> NA >> NB >> M;
  for (int i = 0; i < NA; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < NB; ++i) {
    cin >> B[i];
  }

  int res = 2 * MAX_A + 1;
  for (int i = 0; i < M; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    res = min(A[x - 1] + B[y - 1] - c, res);
  }
  for (int i = 0; i < NA; ++i) {
    for (int j = 0; j < NB; ++j) {
      res = min(A[i] + B[j], res);
    }
  }
  printf("%d\n", res);
}