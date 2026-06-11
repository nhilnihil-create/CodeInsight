#include <cmath>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n, d;
  std::cin >> n >> d;
  std::vector<std::vector<int>> x(n, std::vector<int>(d));
  for (int j = 0; j < n; ++j)
    for (int i = 0; i < d; ++i)
      std::cin >> x.at(j).at(i);

  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int sum = 0;
      for (int k = 0; k < d; ++k) {
        int a = x.at(i).at(k);
        int b = x.at(j).at(k);
        sum += (a - b) * (a - b);
      }
      if ((int)sqrt(sum) == sqrt(sum))
        cnt++;
    }

  std::cout << cnt << std::endl;
}
