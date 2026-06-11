#include <iostream>
#include <vector>
#include <cassert>

int const nmax = 200000;
int const sigma = 50;
int v[5 + nmax], temp[5 + nmax];

void process(int n) {
  for(int i = 0;i <= n; i++)
    temp[i] = 0;
  for(int i = 1;i <= n; i++) {
    temp[std::max(1, i - v[i])]++;
    temp[std::min(n + 1, i + v[i] + 1)]--;
  }
  for(int i = 1;i <= n; i++)
    temp[i] += temp[i - 1];
  for(int i = 1;i <= n; i++)
    v[i] = temp[i];
}

int main() {

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1;i <= std::min(sigma, k); i++)
    process(n);
  for(int i = 1;i <= n; i++)
    std::cout << v[i] << " ";
}
