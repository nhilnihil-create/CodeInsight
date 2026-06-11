#include <iostream>

int main()
{
  int A, B;
  std::cin >> A >> B;
  if (A>B) {
    int t = A; A = B; B = t;
  }
  for (int i=0; i<B; i++) std::cout << A;
  std::cout << std::endl;
  return 0;
}
