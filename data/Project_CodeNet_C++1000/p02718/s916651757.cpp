#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int N, M;
  std::cin >> N >> M;
  
  std::vector<int> items;
  int item;
  float score = 0;
  
  while (std::cin >> item){
    items.push_back(item);
    score += item;
  }
  
  std::sort(items.begin(), items.end(), std::greater<int>());
  
  if (items[M - 1] < score / 4 / M) std::cout << "No";
  else std::cout << "Yes";
  
  return 0;
  
}