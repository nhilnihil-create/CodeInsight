#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int N;
  std::vector<int> v;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }
  std::sort(v.begin(), v.end());

  double resa = 0;
  double ave = v[0];
  for(int i = 0 ; i < (int)v.size() - 1 ; i++){
    ave = (ave + v[i+1]) / 2.0;
  }

  std::cout << ave << std::endl;
  return 0;
}