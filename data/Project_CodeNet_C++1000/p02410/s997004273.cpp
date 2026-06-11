#include <iostream>

const int N = 100;
const int M = 100;

int main(void) {
  int A[N][M] = {0};
  int b[M] = {0};
  int c[M] = {0};

  int n = 0;
  int m = 0;

  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> A[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i] = c[i] +  A[i][j] * b[j];
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << c[i] << std::endl;
  }
  
  return 0;
}