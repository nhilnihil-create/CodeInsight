#include <iostream>
#include <vector>

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> a_to_i(N);
  for(int i=0; i<N; i++) {
    int a;
    std::cin >> a;
    a--;
    a_to_i[a] = i+1;
  }

  for(auto i: a_to_i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
