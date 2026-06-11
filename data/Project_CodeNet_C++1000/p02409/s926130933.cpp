#include <bits/stdc++.h>

int main() {

  int A[5][4][11];
  int N;
  int b, f, r, v;

  for(int i = 0; i < 5; ++i) {
    for(int j = 0; j < 4; ++j) {
      for(int k = 0; k < 11; ++k) {
	A[i][j][k] = 0;
      }
    }
  }

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> b >> f >> r >> v;
    A[b][f][r] += v;
  }

  for(int i = 1; i < 5; ++i) {
    for(int j = 1; j < 4; ++j) {
      for(int k = 1; k < 11; ++k) {
	std::cout << " " << A[i][j][k];
      }
      std::cout << std::endl;
    }
    if( i != 4 ) {
      std::cout << "####################" << std::endl;
    }
  }
  
  return 0;
}