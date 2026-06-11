#include <iostream>
int main()
  {int A, B, C, K, c{}; std::cin >> A >> B >> C >> K;
  for (; A >= B; ++c) B *= 2; for (; B >= C; ++c) C *= 2;
  puts(c <= K ? "Yes" : "No");}