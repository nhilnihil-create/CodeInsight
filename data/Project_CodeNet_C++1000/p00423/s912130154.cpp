#include <iostream>



int main () {
  int n, i;
  int left, right;
  int sum_a, sum_b;
  while (std::cin >> n) {
    if (n == 0) {
      break;
    }
    sum_a = 0;
    sum_b = 0;
    for (i = 0; i < n; i ++) {
      std::cin >> left >> right;

      if (left > right) sum_a += (left + right); 
      else if (left < right) sum_b += (left + right);
      else {
        sum_a += left;
        sum_b += right;
      }
    }
    std::cout << sum_a << " " << sum_b << std::endl;
  }
  return 0;
}