#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;

int A[3][3];
int C[8]{};

int main() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> A[i][j];
    }
  }
  int N;
  unordered_set<int> B;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int b;
    cin >> b;
    B.insert(b);
  }
  for (auto &b : B) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (A[i][j] == b) {
          ++C[i];
          ++C[j + 3];
          C[6] += i + j == 2;
          C[7] += i == j;
          for (int k = 0; k < 8; ++k) {
            if (C[k] >= 3) {
              printf("Yes\n");
              return 0;
            }
          }
        }
      }
    }
  }
  printf("No\n");
}