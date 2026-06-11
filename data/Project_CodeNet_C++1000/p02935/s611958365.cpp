#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;
  double v[50];
  for (int i=0; i<N; i++) std::cin >> v[i];
  std::sort(v, v+N);
  double val = v[0];
  for (int i=1; i<N; i++) {
    val = (val + v[i]) / 2.0;
    v[i] = val;
  }
  std::cout << val << std::endl;
  return 0;
}
