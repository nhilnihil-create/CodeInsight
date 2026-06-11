#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  std::cin >> N;
  double temp = 0;
  for (int i = 0; i < N; i++){
    double a;
    std::cin >> a;
    temp += 1/a;
  }
  std::cout << 1/temp << std::endl;
}