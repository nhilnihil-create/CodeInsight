#include <iostream>
#include <string>
#include <algorithm>

int main(void) {
  std::string word;
  std::string text;

  std::cin >> word;
  std::cin >> text;

  int count = 0;
  
  while (text != "END_OF_TEXT") {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);      
				  
    if (text == word) {
      count++;
    }
    
    std::cin >> text;
  }

  std::cout << count << std::endl;
  
  return 0;
}