#include <bits/stdc++.h>

int main(){
  int N;
  double v[50];
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> v[i];
  }
  std::sort(v, v+N);
  for (int i = 0; i < N; i++) {
    v[i+1] = (v[i] + v[i+1])/2;
  }
  std::cout << v[N-1] << std::endl;
}