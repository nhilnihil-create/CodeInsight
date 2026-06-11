#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> cbt;
  cbt.push_back(0);
  int h;
  std::cin >> h;
  for (int i = 0; i < h; ++i) {
    int k;
    std::cin >> k;
    cbt.push_back(k);
  }
  for (int i = 1; i < h+1; ++i) {
    printf("node %d: key = %d, ", i, cbt[i]);
    if (i != 1)
      printf("parent key = %d, ", cbt[i/2]);
    if (2*i < h+1)
      printf("left key = %d, ", cbt[2*i]);
    if (2*i < h)
      printf("right key = %d, ", cbt[2*i+1]);
    std::cout << std::endl;
  }
}