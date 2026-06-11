#include <iostream>

int main()
{
  int A[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) std::cin >> A[i][j];
  }
  bool marked[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) marked[i][j] = false;
  }
  int N;
  std::cin >> N;
  for (int k=0; k<N; k++) {
    int n;
    std::cin >> n;
    for (int i=0; i<3*3; i++) {
    	if (A[i/3][i%3] == n) { marked[i/3][i%3] = true; break; }
    }
  }
  bool bingo = false;
  for (int i=0; i<3; i++) {
    if (marked[i][0] && marked[i][1] && marked[i][2]) {
      bingo = true; break;
    }
  }
  for (int j=0; j<3; j++) {
    if (marked[0][j] && marked[1][j] && marked[2][j]) {
      bingo = true; break;
    }
  }
  if (marked[0][0] && marked[1][1] && marked[2][2]) bingo = true;
  if (marked[0][2] && marked[1][1] && marked[2][0]) bingo = true;
  if (bingo) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
