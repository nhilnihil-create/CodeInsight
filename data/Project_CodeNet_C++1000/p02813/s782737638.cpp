#include <iostream>
#include <vector>
#include <cmath>

int factorial(int n)
{
  int ret = 1;
  for(int i=0; i<n; i++) {
    ret *= n-i;
  }
  return ret;
}

// num: number created by N!
// digit: digit from left.(0 digit for 4123 is 4)
int get_order(const std::vector<int> &num,
              int digit)
{
  int len = num.size();
  int n = num[digit];
  int used = 0;
  for(int i=0; i<digit; i++) {
    if(num[i] < n) {
      ++used;
    }
  }
  return (n - used - 1) * factorial(len - digit - 1);
}

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> P(N), Q(N);

  for(int i=0; i<N; i++) {
    std::cin >> P[i];
  }
  for(int i=0; i<N; i++) {
    std::cin >> Q[i];
  }

  int order_p = 0, order_q = 0;
  for(int i=0; i<N; i++) {
    order_p += get_order(P, i);
    order_q += get_order(Q, i);
    //    std::cout << "i: " << i
    //              << "order_p: " << order_p
    //              << "order_q: " << order_q
    //              << std::endl;
  }

  std::cout << std::abs(order_p - order_q) << std::endl;
  return 0;
}
