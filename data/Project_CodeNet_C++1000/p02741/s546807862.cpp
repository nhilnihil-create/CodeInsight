#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> a = {1, 1, 1, 2, 1, 2, 1, 5,  2, 2, 1, 5, 1, 2, 1, 14,
                        1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int n;
  std::cin >> n;
  std::cout << a.at(n - 1) << std::endl;
}
