#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

int main()
{
  int N;
  std::cin >> N;
  std::vector<unsigned int> a(N);
  for(int i=0; i<N; i++) {
    std::cin >> a[i];
  }

  unsigned int i=1;
  unsigned int max_a = *std::max_element(a.begin(), a.end());
  while(true) {
    if(max_a < i) {
      break;
    }

    // count 1 of i-bit
    int n = 0;
    for(int j=0; j<N; j++) {
      if(a[j] & i) n++;
    }
    // std::cout << "n: " << n << std::endl;
    if(n % 2 == 1) {
      for(int j=0; j<N; j++) {
        a[j] = a[j] ^ i;
      }
    }
    i = i << 1;
  }

  for(int j=0; j<N; j++) {
    std::cout << a[j] << " ";
  }
  std::cout << std::endl;

  return 0;
}
