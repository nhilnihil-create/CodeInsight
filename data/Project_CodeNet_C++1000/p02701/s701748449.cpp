#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
  std::vector<std::string> gifts;
  std::string gift;
  
  int n;
  std::cin >> n;
  
  while (std::cin >> gift) gifts.push_back(gift);
  
  std::sort(gifts.begin(), gifts.end());
  
  std::string prev = "";
  int count = 0;
  
  for (int i = 0; i < n; i++){
    if (prev != gifts[i]){
      count++;
      prev = gifts[i];
    }
  }
  
  std::cout << count;
  
  return 0;
}